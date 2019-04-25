/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_shifts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:05:06 by tdiaz             #+#    #+#             */
/*   Updated: 2019/03/12 16:05:08 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Comment
*/

#include "fract.h"

int			mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (mlx->freeze == 1)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->image);
		mlx->con_x = (double)x / WIND_X * 3.5 - 2.5;
		mlx->con_y = (double)y / WIND_Y * 2 - 1.0;
		draw_update(mlx);
	}
	return (1);
}

static void	shift_zoom(int button, int x, int y, t_mlx *mlx)
{
	double tmp;

	x = (x - mlx->org_x);
	y = -1 * (y - mlx->org_y);
	tmp = mlx->zoom;
	if (button == 5)
	{
		mlx->zoom *= 0.9;
		mlx->x_shift += -1 * (((double)x / WIND_X) * (mlx->zoom - tmp));
		mlx->y_shift += -1 * (((double)y / WIND_Y) * (mlx->zoom - tmp));
	}
	if (button == 4)
	{
		mlx->zoom *= 1.1;
		mlx->x_shift += -1 * (((double)x / WIND_X) * (mlx->zoom - tmp));
		mlx->y_shift += -1 * (((double)y / WIND_Y) * (mlx->zoom - tmp));
	}
	draw_update(mlx);
}

static void	flame_shift_zoom(int button, int x, int y, t_mlx *mlx)
{
	double tmp;

	x = (x - mlx->org_x);
	y = -1 * (y - mlx->org_y);
	tmp = mlx->flame_zoom;
	if (button == 5)
	{
		mlx->flame_zoom *= 0.9;
		mlx->flame_x_shift += -1.5 * ((double)x / WIND_X) *
			(mlx->flame_zoom - tmp);
		mlx->flame_y_shift += -1.5 * ((double)y / WIND_Y) *
			(mlx->flame_zoom - tmp);
	}
	if (button == 4)
	{
		mlx->flame_zoom *= 1.1;
		mlx->flame_x_shift += -1.5 * ((double)x / WIND_X) *
			(mlx->flame_zoom - tmp);
		mlx->flame_y_shift += -1.5 * ((double)y / WIND_Y) *
			(mlx->flame_zoom - tmp);
	}
	draw_flame(mlx);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (mlx->mode < 2)
		shift_zoom(button, x, y, mlx);
	else
		flame_shift_zoom(button, x, y, mlx);
	return (1);
}
