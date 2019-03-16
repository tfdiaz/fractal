/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:10:06 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/21 11:34:23 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	counter(int *i, intmax_t x, intmax_t base, intmax_t *sgn)
{
	if (x < 0)
	{
		*sgn = -1;
		(*i)++;
	}
	while (x != 0)
	{
		x = x / base;
		(*i)++;
	}
}

char	*zerostr(uintmax_t x)
{
	char *ret;

	if (x == 0)
	{
		ret = ft_strdup("0");
		return (ret);
	}
	return (NULL);
}

char	*itoa_base(intmax_t x, intmax_t base)
{
	int			i;
	char		*str;
	char		*alph;
	intmax_t	sgn;

	i = 0;
	sgn = 1;
	alph = "0123456789abcdef";
	if ((str = zerostr(x)) != NULL)
		return (str);
	counter(&i, x, base, &sgn);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	i--;
	while (x != 0)
	{
		str[i] = alph[x % base * sgn];
		x /= base;
		i--;
	}
	if (sgn == -1)
		str[i] = '-';
	return (str);
}

char	*uitoa_base(uintmax_t x, intmax_t base)
{
	int			i;
	char		*str;
	char		*alph;
	uintmax_t	tmp;

	i = 0;
	tmp = x;
	alph = "0123456789abcdef";
	str = zerostr(x);
	if ((str = zerostr(x)) != NULL)
		return (str);
	while (tmp != 0)
	{
		tmp = tmp / base;
		i++;
	}
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (x != 0)
	{
		tmp = x % base;
		str[--i] = alph[tmp];
		x /= base;
	}
	return (str);
}
