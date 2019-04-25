/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:04:20 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 14:04:24 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the lead function for flame fractal. This algorithm is based on
** Scott Draves and Erik Reckase's paper "The Fractal Flame Algorithm", 2003.
** github: jameswmccarty was also referenced as well. Important note: even
** though the process is built on randomness, we can freeze a frame by saving
** the seed state. This allows a user to hold one image still and increase
** the sample count. A brief explanation of the flame algorithm is to create
** semi-randomized points, run them through a function, create rotated copies,
** and for each pixel on the screen increase the count for that pixel. This
** can be found in flame_render.c The second part of the process is to color
** each pixel correctly from the count. This is done in gamma_correction.c 
*/

#include "flame.h"

void	flame_init(t_flame *flame, t_mlx *mlx)
{
	int	i;

	i = 0;
	flame->num_eq = 16;
	flame->iteration = 125;
	flame->pixels = (t_pix**)malloc(sizeof(t_pix*) * WIND_Y);
	flame->lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * WIND_Y);
	flame->rot = mlx->flame_rot;
	flame->samples = mlx->flame_sample;
	flame->funct = mlx->flame_funct;
	flame->xmax = mlx->flame_zoom;
	flame->ymax = flame->xmax;
	flame->xmin = -1.0 * flame->ymax;
	flame->ymin = flame->xmin;
	flame->x_shift = mlx->flame_x_shift;
	flame->y_shift = mlx->flame_y_shift;
	while (i < WIND_Y)
	{
		flame->pixels[i] = (t_pix*)malloc(sizeof(t_pix) * WIND_X);
		ft_memset(flame->pixels[i], '\0', sizeof(t_pix) * WIND_X);
		pthread_mutex_init(&(flame->lock[i]), NULL);
		i++;
	}
	coeff_init(flame);
}

void	mult_thread(t_flame *flame)
{
	pthread_t	threads[THREAD_COUNT];
	int			i;

	i = -1;
	while (++i < THREAD_COUNT)
		pthread_create(&threads[i], NULL, render, (void*)flame);
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(threads[i], NULL);
}

void	render_out(t_flame *flame, t_mlx *mlx)
{
	int		x;
	int		y;
	t_color r;
	t_color g;
	t_color b;

	y = 0;
	while (y < WIND_Y)
	{
		x = 0;
		while (x < WIND_X)
		{
			r = (flame->pixels[y][x].r & 0xff) << 16;
			g = (flame->pixels[y][x].g & 0xff) << 8;
			b = (flame->pixels[y][x].b & 0xff);
			update_img(mlx, x, y,
				mlx_get_color_value(mlx->mlx_ptr, r + g + b));
			x++;
		}
		y++;
	}
}

void	make_image(t_mlx *mlx)
{
	t_flame		*flame;

	flame = (t_flame *)malloc(sizeof(t_flame));
	flame_init(flame, mlx);
	mult_thread(flame);
	gamma_correction(flame);
	render_out(flame, mlx);
	destroy_and_free(flame);
}

void	draw_flame(t_mlx *mlx)
{
	int					bpp;
	int					size_line;
	int					endian;
	static unsigned int seed = 1;

	srandom(seed);
	srand48(random());
	mlx->image = mlx_new_image(mlx->mlx_ptr, WIND_X, WIND_Y);
	mlx->address = mlx_get_data_addr(mlx->image, &bpp, &size_line, &endian);
	mlx->bpp = bpp;
	mlx->sl = size_line;
	make_image(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image, 0, 0);
	if (mlx->flame_rand)
		seed += random();
	help_screen(mlx);
}
