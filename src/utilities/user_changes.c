/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_changes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:06:45 by tdiaz             #+#    #+#             */
/*   Updated: 2019/03/12 16:06:46 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** See comments from keypress.c and user_shifts.c
*/

#include "../fract.h"

void	reset(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->zoom = 4.0;
	mlx->org_x = WIND_X / 2;
	mlx->org_y = WIND_Y / 2;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	mlx->iter_amount = 230;
	mlx->flame_zoom = 1.0;
	mlx->flame_rot = 3.0;
	mlx->flame_sample = 800;
	mlx->flame_x_shift = 0;
	mlx->flame_y_shift = 0;
	if (mlx->mode == 2)
		draw_flame(mlx);
	else
		draw_update(mlx);
}

void	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	color_shift(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->color_mode ^= 1;
	draw_update(mlx);
}

void	change_iter(char increase, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (increase)
		mlx->iter_amount += 10;
	else
		mlx->iter_amount -= 10;
	draw_update(mlx);
}

void	mode_shift(t_mlx *mlx, int type)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->mode = type;
	if (type < 2)
		draw_update(mlx);
	else
		draw_flame(mlx);
}
