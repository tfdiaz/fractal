/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:07:05 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 14:07:29 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	freeflags(t_flags **flags_set)
{
	if (flags_set == NULL)
		return ;
	free(*flags_set);
	*flags_set = NULL;
}

void	set_length(char **s, t_flags **flags_set)
{
	if (**s == 'h' && (*flags_set)->h)
	{
		(*flags_set)->hh = 1;
		(*flags_set)->h = 0;
	}
	else if (**s == 'l' && (*flags_set)->l)
	{
		(*flags_set)->ll = 1;
		(*flags_set)->l = 0;
	}
	else if (**s == 'h')
		(*flags_set)->h = 1;
	else if (**s == 'l')
		(*flags_set)->l = 1;
	else if (**s == 'j')
		(*flags_set)->j = 1;
	else if (**s == 'z')
		(*flags_set)->z = 1;
}

void	setnumber(char **s, t_flags **flags, va_list ap)
{
	int		x;
	int		i;
	char	str[12];

	i = 0;
	if (**s == '*')
	{
		if ((*flags)->prec)
			(*flags)->preclen = va_arg(ap, int);
		else
			(*flags)->padlen = va_arg(ap, int);
		return ;
	}
	while (**s >= '0' && **s <= '9')
	{
		str[i++] = **s;
		(*s)++;
	}
	(*s)--;
	str[i] = '\0';
	x = ft_atoi(str);
	if ((*flags)->prec)
		(*flags)->preclen = x;
	else
		(*flags)->padlen = x;
}

void	flag_setter(char **s, va_list ap, t_flags **flags_set)
{
	while (argsymb(**s) == FALSE)
	{
		if (**s == '-')
			(*flags_set)->leftjust = 1;
		else if (**s == '0')
			(*flags_set)->zeropad = 1;
		else if (**s == '#')
			(*flags_set)->pound = 1;
		else if (**s == '.')
			(*flags_set)->prec = 1;
		else if (**s == '+')
			(*flags_set)->plus = 1;
		else if ((**s >= '1' && **s <= '9') || **s == '*')
			setnumber(s, flags_set, ap);
		else
			set_length(s, flags_set);
		(*s)++;
	}
}

t_flags	*setflags(char **s, va_list ap)
{
	t_flags *flags_set;

	if ((flags_set = newflags()) == NULL)
		return (NULL);
	if (**s == ' ')
		flags_set->space = 1;
	flag_setter(s, ap, &flags_set);
	if (**s == 'X')
		(flags_set)->x = 1;
	if (**s == 'U')
		(flags_set)->u = 1;
	if (**s == 'D')
		(flags_set)->l = 1;
	if (**s == 's' && flags_set->l)
		**s = 'S';
	if (**s == 'c' && flags_set->l)
		**s = 'C';
	return (flags_set);
}
