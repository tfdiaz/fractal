/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_funct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:56:08 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:56:09 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flame.h"

/*
** More flame functions.
*/

void	wave(double *newx, double *newy, double *arr)
{
	*newx = arr[X] + arr[PA1] * sin(arr[Y] / (arr[PA2] * arr[PA2]));
	*newy = arr[Y] + arr[PA3] * sin(arr[X] / (arr[PA4] * arr[PA4]));
}

void	linear(double *newx, double *newy, double *arr)
{
	*newx = arr[X];
	*newy = arr[Y];
}

void	swirl(double *newx, double *newy, double *arr)
{
	arr[R] = sqrt(arr[X] * arr[X] + arr[Y] * arr[Y]) * M_PI;
	arr[THETA] = atan2(arr[Y], arr[X]) / M_PI;
	*newx = arr[THETA] * sin(arr[R]);
	*newy = arr[THETA] * cos(arr[R]);
}

void	other(double *newx, double *newy, double *arr)
{
	arr[R] = arr[X] * arr[X] + arr[Y] * arr[Y];
	*newx = arr[X] * sin(arr[R]) - arr[Y] * cos(arr[R]);
	*newy = arr[X] * cos(arr[R]) + arr[Y] * sin(arr[R]);
}
