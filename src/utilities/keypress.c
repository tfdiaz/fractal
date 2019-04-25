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
** user_changes/2.c and user_shifts.c
*/

#include "../fract.h"

static void	flame_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		newframe(mlx);
	if (keycode == KEY_LEFT_ARROW)
		flame_rot(mlx, 0);
	if (keycode == KEY_RIGHT_ARROW)
		flame_rot(mlx, 1);
	if (keycode == KEY_UP_ARROW)
		flame_iter(mlx, 1);
	if (keycode == KEY_DOWN_ARROW)
		flame_iter(mlx, 0);
	if (keycode == KEY_S)
		mlx->flame_rand ^= 1;
	if (keycode == KEY_N)
		change_flame(mlx);
}

static void	julia_mandel_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_F)
		mlx->freeze ^= 1;
	if (keycode == KEY_PLUS)
		change_iter(1, mlx);
	if (keycode == KEY_MIN)
		change_iter(0, mlx);
	if (keycode == KEY_W)
		color_shift(mlx);
}

int			key_press(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (keycode == KEY_R)
		reset(mlx);
	if (keycode == KEY_ONE)
		mode_shift(mlx, 0);
	if (keycode == KEY_TWO)
		mode_shift(mlx, 1);
	if (keycode == KEY_THREE)
		mode_shift(mlx, 2);
	if (keycode == KEY_H)
		help_set(mlx);
	if (mlx->mode == 2)
		flame_press(keycode, mlx);
	else
		julia_mandel_press(keycode, mlx);
	return (1);
}
