/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_gamma_correction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:41 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:59:43 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flame.h"

static void	flatten(t_flame *flame, float *max)
{
	int x;
	int y;

	y = 0;
	while (y < WIND_Y)
	{
		x = 0;
		while (x < WIND_X)
		{
			if (flame->pixels[y][x].value.counter != 0)
			{
				flame->pixels[y][x].value.normal = (float)log10((double)
					flame->pixels[y][x].value.counter);
				if (flame->pixels[y][x].value.normal > *max)
					*max = flame->pixels[y][x].value.normal;
			}
			x++;
		}
		y++;
	}
}

static void	color_pixel(t_flame *flame, float max)
{
	int		x;
	int		y;
	double	gamma;

	y = 0;
	gamma = 0.8;
	while (y < WIND_Y)
	{
		x = 0;
		while (x < WIND_X)
		{
			flame->pixels[y][x].value.normal /= max;
			flame->pixels[y][x].r = (unsigned char)
				((float)(flame->pixels[y][x].r)) *
				pow(flame->pixels[y][x].value.normal, (1.0 / gamma));
			flame->pixels[y][x].g = (unsigned char)
				((float)(flame->pixels[y][x].g)) *
				pow(flame->pixels[y][x].value.normal, (1.0 / gamma));
			flame->pixels[y][x].b = (unsigned char)
				((float)(flame->pixels[y][x].b)) *
				pow(flame->pixels[y][x].value.normal, (1.0 / gamma));
			x++;
		}
		y++;
	}
}

void		gamma_correction(t_flame *flame)
{
	float	max;

	max = 0.0;
	flatten(flame, &max);
	color_pixel(flame, max);
}
