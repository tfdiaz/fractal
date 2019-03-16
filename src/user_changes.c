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

#include "fract.h"

void	reset(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->zoom = 4.0;
	mlx->org_x = WIND_X/2;
	mlx->org_y = WIND_Y/2;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	draw_update(mlx);
}

void	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	color_shift(char type, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->color_mode = (int)type;
	draw_update(mlx);
}

// void	xy_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->xy_shift += SPEED;
// 		if (mlx->xy_shift > 1.0)
// 			mlx->xy_shift = 1.0;
// 	}
// 	else
// 	{
// 		mlx->xy_shift -= SPEED;
// 		if (mlx->xy_shift < -1.0)
// 			mlx->xy_shift = -1.0;
// 	}
// 	draw_update(mlx);
// }
