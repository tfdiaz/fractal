/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:25:53 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:25:56 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void help_flame(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .30, 0xd5fdfe,
		"* N - Cyclic flame function");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .35, 0xd5fdfe,
		"* S - Stop flame randomization");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .40, 0xd5fdfe,
		"* A - New flame image");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .45, 0xd5fdfe,
		"* UP Key - Increase flame samples");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .50, 0xd5fdfe,
		"* DOWN Key - Decrease flame samples");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .55, 0xd5fdfe,
		"* RIGHT Key - Increase flame rotation");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .60, 0xd5fdfe,
		"* LEFT Key - Decrease flame rotation");
}

static void help_mode(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .05, 0xd5fdfe,
		"Key -- Action");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .1, 0xd5fdfe,
		"1 - Mode: Julia");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .06, WIND_Y * .15, 0xd5fdfe,
		"* F - Unfreeze/freeze Julia with mouse");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .20, 0xd5fdfe,
		"2 - Mode: Mandelbrot");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .25, 0xd5fdfe,
		"3 - Mode: Flame");
}

static void help_uts(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .70, 0xd5fdfe,
		"R - Reset");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .75, 0xd5fdfe,
		"H - Hide/Show Help");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .80, 0xd5fdfe,
		"W - Smooth/Crazy Color Mode for Julia and Mandelbrot");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .85, 0xd5fdfe,
		"+/- Key - Increase/Decrease iteration for Julia and Mandelbrot");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIND_X * .05, WIND_Y * .90, 0xd5fdfe,
		"Created by Tomas Diaz: github - tfdiaz");
}

void		help_screen(t_mlx *mlx)
{
	if (mlx->help)
	{
		help_mode(mlx);
		help_flame(mlx);
		help_uts(mlx);
	}
}
