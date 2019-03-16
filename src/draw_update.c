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

int		iterator(int x, int y, t_mlx *mlx)
{
	x = (x - mlx->org_x);
	y = -1 * (y - mlx->org_y);
	double zx = ((double)x / WIND_X) * mlx->zoom + mlx->x_shift;
	double zy = ((double)y / WIND_Y) * mlx->zoom + mlx->y_shift;
	double xtemp;

	int iter = 0;
	while (zx * zx + zy * zy < 4 && iter < mlx->iter_amount)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + mlx->con_y;
		zx = xtemp + mlx->con_x;

		iter += 1;
	}

	if (iter == mlx-> iter_amount)
		return 0;
	else
		return (iter);
}

// int		iterator(int x, int y, t_mlx *mlx)
// {
// 	double zx = ((double)x / WIND_X) * 3.5 - 2.5;
// 	double zy = ((double)y / WIND_Y) * 2.0 - 1;
// 	double xtemp;

// 	int iter = 0;
// 	while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
// 	{
// 		xtemp = pow((zx * zx + zy * zy),(BODY_COUNT/2)) * cos(BODY_COUNT * atan2(zy, zx)) + mlx->con_x;
// 		zy = pow((zx * zx + zy * zy),(BODY_COUNT/2)) * sin(BODY_COUNT * atan2(zy, zx)) + mlx->con_y;
// 		zx = xtemp;

// 		iter += 1;
// 	}

// 	if (iter == MAX_ITER)
// 		return 0;
// 	else
// 		return (iter);
// }

void	*oct1(void *param)
{
	int x;
	int y;
	t_par *par;
	t_mlx *mlx;

	par = (t_par *)param;
	mlx = par->mlx;
	int val = par->mod;
	y = 0;
	while (y < WIND_Y)
	{
		x = val;
		while (x < WIND_X)
		{
			t_color color = set_color(mlx, iterator(x, y, mlx));
			update_img(mlx, x, y, color);
			x += THREAD_COUNT;
		}
		y++;
	}
	return NULL;
}

void	sweep_and_color(t_mlx *mlx)
{
	pthread_t val[THREAD_COUNT];
	t_par *arr[THREAD_COUNT];
	int i;

	i = 0;
	while (i < THREAD_COUNT)
	{
		arr[i] = (t_par*)malloc(sizeof(t_par));
		arr[i]->mlx = mlx;
		arr[i]->mod = i;
		pthread_create(&val[i], NULL, oct1, (void*)arr[i]);
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

void		draw_update(t_mlx *mlx)
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
}

// void	sweep_and_color(t_mlx *mlx)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < WIND_Y)
// 	{
// 		x = 0;
// 		while (x < WIND_X)
// 		{
// 			mlx->color = set_color(mlx, iterator(x, y, mlx));
// 			update_img(mlx, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }