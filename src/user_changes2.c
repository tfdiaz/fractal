/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_changes2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:28:09 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 16:28:12 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	change_flame(t_mlx *mlx)
{
	if (mlx->mode == 2)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->image);
		mlx->flame_funct = (mlx->flame_funct + 1) % 8;
		draw_flame(mlx);
	}
}

void	newframe(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	draw_flame(mlx);
}

void	flame_rot(t_mlx *mlx, int flag)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (flag)
		mlx->flame_rot++;
	else
		mlx->flame_rot--;
	if (mlx->flame_rot < 1)
		mlx->flame_rot = 1;
	draw_flame(mlx);
}

void	flame_iter(t_mlx *mlx, int flag)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (flag)
		mlx->flame_sample += 50;
	else
		mlx->flame_sample -= 50;
	if (mlx->flame_sample < 1)
		mlx->flame_sample = 1;
	draw_flame(mlx);
}

void	help_set(t_mlx *mlx)
{
	mlx->help ^= 1;
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	if (mlx->mode == 2)
		draw_flame(mlx);
	else
		draw_update(mlx);
}
