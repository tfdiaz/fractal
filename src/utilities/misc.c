/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:52:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/03/13 09:52:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Simple utilities functions that did not have a place to go.
*/

#include "../fract.h"

int				closes(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

unsigned int	set_color(t_mlx *mlx, double iter)
{
	if (mlx->color_mode == 0)
		return (color_smooth(mlx, iter));
	else
		return (color_crazy(mlx, iter));
}

void			update_img(t_mlx *mlx, int x, int y, t_color color)
{
	int	j;

	j = 0;
	while (j < mlx->bpp / 8)
	{
		*(mlx->address + (mlx->sl * y + mlx->bpp * x / 8 + j)) =
			(color >> (8 * j)) & 0xFF;
		j++;
	}
}

double			shift_xcoord(double x, t_mlx *mlx)
{
	x = (x - mlx->org_x);
	return ((x / WIND_X) * mlx->zoom + mlx->x_shift);
}

double			shift_ycoord(double y, t_mlx *mlx)
{
	y = -1 * (y - mlx->org_y);
	return ((y / WIND_Y) * mlx->zoom + mlx->y_shift);
}
