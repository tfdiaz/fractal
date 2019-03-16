/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:48:00 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/17 16:48:01 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
*/

#include "fract.h"

void	build(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIND_X, WIND_Y, "Tomas Diaz");
	draw_update(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, (void*)mlx);
	mlx_hook(mlx->win_ptr, 3, 0, key_press, (void*)mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, (void*)mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, (void*)mlx);
	mlx_hook(mlx->win_ptr, 17, 0, closes, (void*)mlx);
	mlx_loop(mlx->mlx_ptr);
}

t_mlx	*constructor(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->color_mode = 1;
	mlx->con_x = -.8;
	mlx->con_y = .156;
	mlx->zoom = 4.0;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	mlx->org_x = WIND_X / 2;
	mlx->org_y = WIND_Y / 2;
	mlx->freeze = 0;
	mlx->iter_amount = 100;
	return (mlx);
}

int		main(void)
{
	t_mlx	*mlx;
		
	mlx = constructor();
	build(mlx);
	return (0);
}
