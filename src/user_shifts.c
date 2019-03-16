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
**
*/

#include "fract.h"

// void	theta_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->theta += SPEED;
// 		if (mlx->theta > M_PI)
// 			mlx->theta = -1.0 * M_PI;
// 	}
// 	else
// 	{
// 		mlx->theta -= SPEED;
// 		if (mlx->theta < -1.0 * M_PI)
// 			mlx->theta = M_PI;
// 	}
// 	draw_update(mlx);
// }

// void	phi_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->phi += SPEED;
// 		if (mlx->phi > 2.0 * M_PI)
// 			mlx->phi = 0.0;
// 	}
// 	else
// 	{
// 		mlx->phi -= SPEED;
// 		if (mlx->phi < 0)
// 			mlx->phi = 2.0 * M_PI;
// 	}
// 	draw_update(mlx);
// }

// void	z_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->z_shift += SPEED;
// 		if (mlx->z_shift > 1.0)
// 			mlx->z_shift = 1.0;
// 	}
// 	else
// 	{
// 		mlx->z_shift -= SPEED;
// 		if (mlx->z_shift < 0.0)
// 			mlx->z_shift = 0.0;
// 	}
// 	draw_update(mlx);
// }

// void	zoom_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->zoom -= SPEED;
// 		if (mlx->zoom < 0.2)
// 			mlx->zoom = 0.2;
// 	}
// 	else
// 	{
// 		mlx->zoom += SPEED;
// 		if (mlx->zoom > 2.0)
// 			mlx->zoom = 2.0;
// 	}
// 	draw_update(mlx);
// }

// void	focal_shift(char type, t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
// 	if (type)
// 	{
// 		mlx->f_len += SPEED;
// 		if (mlx->f_len > 2.0)
// 			mlx->f_len = 2.0;
// 	}
// 	else
// 	{
// 		mlx->f_len -= SPEED;
// 		if (mlx->f_len < 0.2)
// 			mlx->f_len = 0.2;
// 	}
// 	draw_update(mlx);
// }
