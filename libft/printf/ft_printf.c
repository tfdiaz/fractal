/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:33:27 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/20 16:33:30 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dispatch	g_dispatch[10] = {
	{.prt = &prt_ptr, .s = "p"},
	{.prt = &prt_str, .s = "s"},
	{.prt = &prt_oct, .s = "oO"},
	{.prt = &prt_wstr, .s = "S"},
	{.prt = &prt_int, .s = "idD"},
	{.prt = &prt_uint, .s = "uU"},
	{.prt = &prt_hex, .s = "xX"},
	{.prt = &prt_c, .s = "cC"},
	{.prt = &prt_percent, .s = "%"},
	{0, 0}
};

void	funct(char **s, va_list ap, t_vect **vect)
{
	t_flags	*flags_set;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flags_set = setflags(s, ap);
	while (g_dispatch[i].prt != NULL)
	{
		j = 0;
		while (g_dispatch[i].s[j] != '\0')
		{
			if (**s == g_dispatch[i].s[j])
				g_dispatch[i].prt(ap, &flags_set, vect);
			j++;
		}
		i++;
	}
	freeflags(&flags_set);
	(*s)++;
}

size_t	parsefor(char *s, va_list ap)
{
	t_vect	*vect;
	char	str[2];
	size_t	x;

	str[1] = '\0';
	vect = vect_new();
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			funct(&s, ap, &vect);
		}
		else
		{
			str[0] = *s;
			vect_add(vect, str, ft_strlen(str));
			s++;
		}
	}
	prtputstr((char*)vect->content);
	x = vect->ctsize;
	vect_free(&vect);
	return (x);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	int		x;

	va_start(ap, format);
	s = prtstrdup(format);
	x = (int)parsefor(s, ap);
	va_end(ap);
	free(s);
	return (x);
}
