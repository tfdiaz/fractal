/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octhex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:41:57 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 15:42:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_check(char **str, t_flags **f_set)
{
	if ((*f_set)->pound && !(*f_set)->leftjust && !(*f_set)->zeropad)
	{
		*str = joinfree("0x", str);
		(*f_set)->pound = 0;
	}
	if ((*f_set)->pound && ((*f_set)->leftjust || (*f_set)->zeropad))
		(*f_set)->padlen -= 2;
	while ((*f_set)->preclen > (int)ft_strlen(*str))
		*str = joinfree("0", str);
	(*f_set)->padlen -= ft_strlen(*str);
	if ((*f_set)->leftjust)
	{
		if ((*f_set)->pound)
			*str = joinfree("0x", str);
		*str = joinclean(str, f_set, 1);
	}
	else
	{
		*str = joinclean(str, f_set, 0);
		if ((*f_set)->pound && (*str)[0] != ' ')
			*str = joinfree("0x", str);
	}
}

void	prt_hex(va_list ap, t_flags **f_set, t_vect **vect)
{
	char		*str;
	uintmax_t	x;

	x = va_arg(ap, uintmax_t);
	if (x == 0)
		(*f_set)->pound = 0;
	uconvert(&x, f_set);
	str = uitoa_base(x, 16);
	zeroperc(&str, f_set);
	hex_check(&str, f_set);
	if ((*f_set)->x)
		prtup_str(&str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void	prt_oct(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char	*str;
	t_byte	tmp;

	tmp = (*flags_set)->pound;
	str = uitoa_base(va_arg(ap, intmax_t), 8);
	zeroperc(&str, flags_set);
	if (tmp && str[0] != '0')
	{
		str = joinfree("0", &str);
		(*flags_set)->pound = 0;
	}
	while ((*flags_set)->preclen > (int)ft_strlen(str))
		str = joinfree("0", &str);
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if ((*flags_set)->leftjust)
		str = joinclean(&str, flags_set, 1);
	else
		str = joinclean(&str, flags_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void	prt_ptr(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char		*str;
	intmax_t	x;

	x = va_arg(ap, void *) - (void*)0;
	str = itoa_base(x, 16);
	while ((*flags_set)->preclen > (int)ft_strlen(str))
		str = joinfree("0", &str);
	str = joinfree("0x", &str);
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if ((*flags_set)->leftjust)
		str = joinclean(&str, flags_set, 1);
	else
		str = joinclean(&str, flags_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}
