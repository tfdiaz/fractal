/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:35:57 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 14:36:18 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sconvert(intmax_t *x, t_flags **flags_set)
{
	if ((*flags_set)->hh)
		*x = (signed char)*x;
	else if ((*flags_set)->h)
		*x = (signed short int)*x;
	else if ((*flags_set)->l)
		*x = (signed long int)*x;
	else if ((*flags_set)->ll)
		*x = (signed long long int)*x;
	else if ((*flags_set)->j)
		*x = (intmax_t)*x;
	else if ((*flags_set)->z)
		*x = (size_t)*x;
	else
		*x = (signed int)*x;
}

void	uconvert(uintmax_t *x, t_flags **flags_set)
{
	if ((*flags_set)->hh)
		*x = (unsigned char)*x;
	else if ((*flags_set)->h)
		*x = (unsigned short int)*x;
	else if ((*flags_set)->l)
		*x = (unsigned long int)*x;
	else if ((*flags_set)->ll)
		*x = (unsigned long long int)*x;
	else if ((*flags_set)->j)
		*x = (uintmax_t)*x;
	else if ((*flags_set)->z)
		*x = (size_t)*x;
	else
		*x = (unsigned int)*x;
}

t_bool	argsymb(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'i' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c'
		|| c == 'C' || c == 'p' || c == '%' || c == '\0')
		return (TRUE);
	return (FALSE);
}

t_flags	*newflags(void)
{
	t_flags	*new_fl;

	if ((new_fl = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	new_fl->leftjust = 0;
	new_fl->zeropad = 0;
	new_fl->pound = 0;
	new_fl->prec = 0;
	new_fl->padlen = 0;
	new_fl->preclen = 0;
	new_fl->plus = 0;
	new_fl->hh = 0;
	new_fl->h = 0;
	new_fl->l = 0;
	new_fl->ll = 0;
	new_fl->j = 0;
	new_fl->z = 0;
	new_fl->x = 0;
	new_fl->space = 0;
	new_fl->u = 0;
	return (new_fl);
}

void	zeroperc(char **s, t_flags **flags_set)
{
	if (**s == '0' && (*flags_set)->prec && (*flags_set)->preclen == 0)
	{
		**s = '\0';
		(*flags_set)->pound = 0;
		(*flags_set)->zeropad = 0;
	}
}
