/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:01:56 by tdiaz             #+#    #+#             */
/*   Updated: 2019/03/12 16:02:10 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Minilibx comes with hooks to grab certain keypresses. The functions below
** map keys to individual actions. All additional functions can be found in
** user_changes.c and user_shifts.c
*/

#include "fract.h"

int		mouse_move(int x, int y, void *param)
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

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx *mlx;
	mlx = (t_mlx*)param;
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	x = (x - mlx->org_x);
	y = -1 * (y - mlx->org_y);
	double tmp = mlx->zoom;
	if (button == 5)
	{
		mlx->zoom *= 0.9;
		mlx->x_shift += -1 * (((double)x/WIND_X) * (mlx->zoom - tmp));
		mlx->y_shift += -1 * (((double)y/WIND_Y) * (mlx->zoom - tmp));
	}
	if (button == 4)
	{
		mlx->zoom *= 1.1;
		mlx->x_shift += -1 * (((double)x/WIND_X) * (mlx->zoom - tmp));
		mlx->y_shift += -1 * (((double)y/WIND_Y) * (mlx->zoom - tmp));
	}
	draw_update(mlx);
	return (1);
}

void		change_iter(char increase, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (increase)
		mlx->iter_amount += 10;
	else
		mlx->iter_amount -= 10;
	draw_update(mlx);
}

int			key_press(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	// if (keycode > KEY_TWO)
	// 	key_press_helper(keycode, mlx);
	if (keycode == KEY_R)
		reset(mlx);
	if (keycode == KEY_F)
		mlx->freeze ^= 1;
		
	if (keycode == KEY_PLUS)
		change_iter(1, mlx);
	if (keycode == KEY_MIN)
		change_iter(0, mlx);
	// if (keycode == KEY_S)
	// 	zoom_shift(0, mlx);
	// if (keycode == KEY_D)
	// 	xy_shift(1, mlx);
	// if (keycode == KEY_A)
	// 	xy_shift(0, mlx);
	// if (keycode == KEY_ONE)
	// 	color_shift(1, mlx);
	// if (keycode == KEY_TWO)
	// 	color_shift(2, mlx);
	return (1);
}
