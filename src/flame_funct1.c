/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_funct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:42:22 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:42:24 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flame.h"

void	flame_function(double *newx, double *newy, double *arr, t_flame *flame)
{
	void (*functs[8])(double*, double*, double*);

	functs[0] = wave;
	functs[1] = wave2;
	functs[2] = other;
	functs[3] = space;
	functs[4] = ball;
	functs[5] = bent;
	functs[6] = swirl;
	functs[7] = linear;
	functs[flame->funct](newx, newy, arr);
}

void	bent(double *newx, double *newy, double *arr)
{
	if (arr[X] >= 0.0 && arr[Y] >= 0.0)
	{
		*newx = arr[X];
		*newy = arr[Y];
	}
	else if (arr[X] < 0.0 && arr[Y] >= 0.0)
	{
		*newx = 2.0 * arr[X];
		*newy = arr[Y];
	}
	else if (arr[X] >= 0.0 && arr[Y] < 0.0)
	{
		*newx = arr[X];
		*newy = arr[Y] * .5;
	}
	else if (arr[X] < 0.0 && arr[Y] < 0.0)
	{
		*newx = 2.0 * arr[X];
		*newy = arr[Y] * .5;
	}
}

void	ball(double *newx, double *newy, double *arr)
{
	arr[R] = sqrt(arr[X] * arr[X] + arr[Y] * arr[Y]);
	arr[THETA] = atan2(arr[Y], arr[X]);
	*newx = sin(arr[THETA]) * cos(arr[R]);
	*newy = cos(arr[THETA]) * sin(arr[R]);
}

void	space(double *newx, double *newy, double *arr)
{
	arr[R] = sqrt(arr[X] * arr[X] + arr[Y] * arr[Y]);
	arr[THETA] = atan2(arr[Y], arr[X]);
	arr[P0] = sin(arr[THETA] + arr[R]);
	arr[P0] = arr[P0] * arr[P0] * arr[P0];
	arr[P1] = cos(arr[THETA] - arr[R]);
	arr[P1] = arr[P1] * arr[P1] * arr[P1];
	*newx = arr[R] * (arr[P0] + arr[P1]);
	*newy = arr[R] * (arr[P0] - arr[P1]);
}

void	wave2(double *newx, double *newy, double *arr)
{
	*newx = arr[X] + arr[C] * sin(tan(3.0 * arr[Y]));
	*newy = arr[Y] + arr[F] * sin(tan(3.0 * arr[X]));
}
