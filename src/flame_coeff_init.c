/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame_coeff_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:51:30 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:51:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flame.h"

static void	randomize(double *a, double *b, double *d, double *e)
{
	*a = drand48();
	*d = RANDR(*a * *a, 1);
	if (random_bit())
		*d = -*d;
	while ((*a * *a + *d * *d) > 1)
	{
		*a = drand48();
		*d = RANDR(*a * *a, 1);
		if (random_bit())
			*d = -*d;
	}
	*b = drand48();
	*e = RANDR(*b * *b, 1);
	if (random_bit())
		*e = -*e;
	while ((*b * *b + *e * *e) > 1)
	{
		*b = drand48();
		*e = RANDR(*b * *b, 1);
		if (random_bit())
			*e = -*e;
	}
}

static void	coeff_set(t_coeff *coeff)
{
	double a;
	double b;
	double d;
	double e;

	randomize(&a, &b, &d, &e);
	while ((a * a + b * b + d * d + e * e) >
			(1 + (a * e - d * b) * (a * e - d * b)))
		randomize(&a, &b, &d, &e);
	coeff->ac = a;
	coeff->bc = b;
	coeff->cc = RANDR(-2, 2);
	coeff->dc = d;
	coeff->ec = e;
	coeff->fc = RANDR(-2, 2);
}

static void	coeff_rand(t_flame *flame, int i)
{
	flame->array_coeff[i].ac = RANDR(-1.5, 1.5);
	flame->array_coeff[i].bc = RANDR(-1.5, 1.5);
	flame->array_coeff[i].cc = RANDR(-1.5, 1.5);
	flame->array_coeff[i].dc = RANDR(-1.5, 1.5);
	flame->array_coeff[i].ec = RANDR(-1.5, 1.5);
	flame->array_coeff[i].fc = RANDR(-1.5, 1.5);
}

static void	coeff_color_set(t_flame *flame, int i)
{
	flame->array_coeff[i].pa1 = RANDR(-2, 2);
	flame->array_coeff[i].pa2 = RANDR(-2, 2);
	flame->array_coeff[i].pa3 = RANDR(-2, 2);
	flame->array_coeff[i].pa4 = RANDR(-2, 2);
	flame->array_coeff[i].r = (unsigned char)(64 + RANDR(64, 256));
	flame->array_coeff[i].g = (unsigned char)(64 + RANDR(64, 256));
	flame->array_coeff[i].b = (unsigned char)(64 + RANDR(64, 256));
}

void		coeff_init(t_flame *flame)
{
	int i;

	i = 0;
	flame->array_coeff = (t_coeff*)malloc(sizeof(t_coeff) * flame->num_eq);
	while (i < flame->num_eq)
	{
		if (random_bit())
			coeff_set(&(flame->array_coeff[i]));
		else
			coeff_rand(flame, i);
		coeff_color_set(flame, i);
		i++;
	}
}
