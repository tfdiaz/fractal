/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_prt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:57:29 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 17:57:44 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_set(char **str, t_flags **f_set)
{
	if ((*str)[0] == '-')
	{
		(*f_set)->preclen++;
		(*f_set)->plus = 0;
	}
	while ((*f_set)->preclen > (int)ft_strlen(*str))
		*str = joinfree("0", str);
	if ((*f_set)->preclen == (int)ft_strlen(*str))
		(*f_set)->zeropad = 0;
	if (((*f_set)->plus) && !(*f_set)->zeropad)
	{
		*str = joinfree("+", str);
		(*f_set)->space = 0;
		(*f_set)->plus = 0;
	}
	(*f_set)->padlen -= ft_strlen(*str);
	if ((*f_set)->space && (*str)[0] != '-')
		*str = joinfree(" ", str);
	if ((*f_set)->leftjust)
		*str = joinclean(str, f_set, 1);
	else
		*str = joinclean(str, f_set, 0);
}

void	prt_int(va_list ap, t_flags **f_set, t_vect **vect)
{
	char		*str;
	intmax_t	x;

	x = ((*f_set)->l || (*f_set)->ll || (*f_set)->j || (*f_set)->z) ?
		(intmax_t)va_arg(ap, intmax_t) : (intmax_t)va_arg(ap, int);
	sconvert(&x, f_set);
	str = itoa_base(x, 10);
	zeroperc(&str, f_set);
	int_set(&str, f_set);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void	prt_uint(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char		*str;
	uintmax_t	x;

	x = va_arg(ap, uintmax_t);
	if ((*flags_set)->u == 0)
		uconvert(&x, flags_set);
	str = uitoa_base(x, 10);
	if (str[0] == '-')
	{
		(*flags_set)->preclen++;
		(*flags_set)->plus = 0;
	}
	while ((*flags_set)->preclen > (int)ft_strlen(str))
		str = joinfree("0", &str);
	if ((*flags_set)->preclen == (int)ft_strlen(str))
		(*flags_set)->zeropad = 0;
	(*flags_set)->padlen -= ft_strlen(str);
	if ((*flags_set)->leftjust)
		str = joinclean(&str, flags_set, 1);
	else
		str = joinclean(&str, flags_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}
