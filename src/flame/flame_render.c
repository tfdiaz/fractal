/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:34 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 16:06:36 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** These functions will determine if a sample point increments the pixel
** count at that point and sets the color. Take a look at flame_funct1 and 
** flame_funct2 to see the different type of images that can be produced. "N"
** press will allow the user to cycle through these functions.
*/

#include "flame.h"

static void	set_point_color(t_flame *flame, t_pix *point, int i)
{
	if (!point->value.counter)
	{
		point->r = flame->array_coeff[i].r;
		point->g = flame->array_coeff[i].g;
		point->b = flame->array_coeff[i].b;
	}
	else
	{
		point->r = (unsigned char)((point->r + flame->array_coeff[i].r) / 2);
		point->g = (unsigned char)((point->g + flame->array_coeff[i].g) / 2);
		point->b = (unsigned char)((point->b + flame->array_coeff[i].b) / 2);
	}
}

static void	in_map(t_flame *flame, double *arr, int i)
{
	unsigned int	x1;
	unsigned int	y1;
	t_pix			*point;

	x1 = (unsigned int)(((flame->xmax + arr[XROT]) /
			(2 * flame->xmax)) * WIND_X);
	y1 = (unsigned int)(((flame->ymax - arr[YROT]) /
			(2 * flame->ymax)) * WIND_Y);
	if (x1 < WIND_X && y1 < WIND_Y)
	{
		pthread_mutex_lock(&(flame->lock[y1]));
		point = &flame->pixels[y1][x1];
		set_point_color(flame, point, i);
		point->value.counter++;
		pthread_mutex_unlock(&(flame->lock[y1]));
	}
}

static void	set_inter_arr(t_flame *flame, double *arr, int i)
{
	arr[PA1] = flame->array_coeff[i].pa1;
	arr[PA2] = flame->array_coeff[i].pa2;
	arr[PA3] = flame->array_coeff[i].pa3;
	arr[PA4] = flame->array_coeff[i].pa4;
	arr[C] = flame->array_coeff[i].cc;
	arr[F] = flame->array_coeff[i].fc;
	arr[B] = flame->array_coeff[i].bc;
	arr[E] = flame->array_coeff[i].ec;
	arr[X] = flame->array_coeff[i].ac * arr[NEWX] +
				flame->array_coeff[i].bc * arr[NEWY] +
				flame->array_coeff[i].cc;
	arr[Y] = flame->array_coeff[i].dc * arr[NEWX] +
				flame->array_coeff[i].ec * arr[NEWY] +
				flame->array_coeff[i].fc;
}

static void	check_step(t_flame *flame, double *arr, int i)
{
	int s;

	s = 1;
	arr[THETA2] = 0.0;
	while (s < flame->rot)
	{
		arr[THETA2] += ((2 * M_PI) / s);
		arr[XROT] = arr[NEWX] * cos(arr[THETA2]) -
					arr[NEWY] * sin(arr[THETA2]) - flame->x_shift;
		arr[YROT] = arr[NEWX] * sin(arr[THETA2]) +
					arr[NEWY] * cos(arr[THETA2]) - flame->y_shift;
		if (arr[XROT] >= flame->xmin && arr[XROT] <= flame->xmax &&
			arr[YROT] >= flame->ymin && arr[YROT] <= flame->ymax)
			in_map(flame, arr, i);
		s++;
	}
}

void		*render(void *fl)
{
	t_flame	*flame;
	int		num;
	int		i;
	int		step;
	double	arr[20];

	flame = (t_flame*)fl;
	num = 0;
	while (num < flame->samples)
	{
		arr[NEWX] = RANDR(flame->xmin, flame->xmax);
		arr[NEWY] = RANDR(flame->ymin, flame->ymax);
		step = -20;
		while (step < flame->iteration)
		{
			i = random() % flame->num_eq;
			set_inter_arr(flame, arr, i);
			flame_function(&arr[NEWX], &arr[NEWY], arr, flame);
			if (step > 0)
				check_step(flame, arr, i);
			step++;
		}
		num++;
	}
	return (NULL);
}
