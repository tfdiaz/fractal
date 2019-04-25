/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:51:16 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 16:51:19 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAME_H
# define FLAME_H

# include "fract.h"

# define PA1	1
# define PA2	2
# define PA3	3
# define PA4	4
# define THETA	5
# define R		6
# define P1		7
# define P0		8
# define C		9
# define F		10
# define B		11
# define E		12
# define X		13
# define Y		14
# define NEWX	15
# define NEWY	16
# define THETA2	17
# define XROT	18
# define YROT	19
# define RANDR(lo,hi) ((lo) + (((hi)-(lo)) * drand48()))

void	bent(double *newx, double *newy, double *arr);
void	ball(double *newx, double *newy, double *arr);
void	space(double *newx, double *newy, double *arr);
void	wave2(double *newx, double *newy, double *arr);
void	other(double *newx, double *newy, double *arr);
void	swirl(double *newx, double *newy, double *arr);
void	linear(double *newx, double *newy, double *arr);
void	wave(double *newx, double *newy, double *arr);

int		random_bit(void);
void	coeff_init(t_flame *flame);

void	flame_function(double *newx, double *newy, double *arr, t_flame *flame);
void	gamma_correction(t_flame *flame);
void	*render(void *fl);
void	destroy_and_free(t_flame *flame);
double	modulus(double a, double b);
int		random_bit(void);

#endif
