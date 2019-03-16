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
**
*/

#include "fract.h"

int				closes(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

unsigned int	set_color(t_mlx *mlx, int iter)
{
	int		shift;

	if (mlx->color_mode == 1)
	{
		shift = iter * 70000;
		return (mlx_get_color_value(mlx->mlx_ptr, 0x000000 + shift));
	}
	else
		return (mlx_get_color_value(mlx->mlx_ptr, 0x00FFFF));
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
