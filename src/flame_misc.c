/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:18:10 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 16:18:12 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flame.h"

int		random_bit(void)
{
	return (random() & 01);
}

double	modulus(double a, double b)
{
	int	cast;

	cast = (int)(a / b);
	return (a - ((double)cast * b));
}

void	destroy_and_free(t_flame *flame)
{
	int	i;

	i = 0;
	while (i < WIND_Y)
	{
		free(flame->pixels[i]);
		i++;
	}
	free(flame->pixels);
	free(flame->lock);
}
