/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:33:55 by tdiaz             #+#    #+#             */
/*   Updated: 2019/03/12 20:33:56 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Try changing the coordinate system as it changes.
*/

#include "fract.h"

static double	julia(double x, double y, t_mlx *mlx)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		iter;

	zx = shift_xcoord(x, mlx);
	zy = shift_ycoord(y, mlx);
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < mlx->iter_amount)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + mlx->con_y;
		zx = xtemp + mlx->con_x;
		iter += 1;
	}
	if (iter == mlx->iter_amount)
		return (0.0);
	else
		return ((double)iter);
}

static double	mandel(double x, double y, t_mlx *mlx)
{
	double	x0;
	double	y0;
	double	xtemp;
	int		iter;

	x0 = shift_xcoord(x, mlx);
	y0 = shift_ycoord(y, mlx);
	x = 0.0;
	y = 0.0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < mlx->iter_amount)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = (2 * x * y) + y0;
		x = xtemp;
		iter += 1;
	}
	if (iter == mlx->iter_amount)
		return (0.0);
	else
		return (double)iter;
}

static void		*send_out(void *param)
{
	int		x;
	int		y;
	int		val;
	t_par	*par;
	t_mlx	*mlx;

	par = (t_par *)param;
	mlx = par->mlx;
	val = par->mod;
	y = 0;
	while (y < WIND_Y)
	{
		x = val;
		while (x < WIND_X)
		{
			update_img(mlx, x, y,
				set_color(mlx, par->funct((double)x, (double)y, mlx)));
			x += THREAD_COUNT;
		}
		y++;
	}
	return (NULL);
}

static void		sweep_and_color(t_mlx *mlx)
{
	pthread_t	val[THREAD_COUNT];
	t_par		*arr[THREAD_COUNT];
	int			i;

	i = 0;
	while (i < THREAD_COUNT)
	{
		arr[i] = (t_par*)malloc(sizeof(t_par));
		arr[i]->mlx = mlx;
		arr[i]->mod = i;
		if (mlx->mode == 0)
			arr[i]->funct = julia;
		else
			arr[i]->funct = mandel;
		pthread_create(&val[i], NULL, send_out, (void*)arr[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(val[i], NULL);
		free(arr[i]);
		i++;
	}
}

void			draw_update(t_mlx *mlx)
{
	int bpp;
	int size_line;
	int endian;

	mlx->image = mlx_new_image(mlx->mlx_ptr, WIND_X, WIND_Y);
	mlx->address = mlx_get_data_addr(mlx->image, &bpp, &size_line, &endian);
	mlx->bpp = bpp;
	mlx->sl = size_line;
	sweep_and_color(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image, 0, 0);
	help_screen(mlx);
}
