/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:13:09 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/11 14:12:42 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wdlen(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*s;
	unsigned int	tmp;

	len = wdlen(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if ((s = ft_strnew(len)) == NULL)
		return (NULL);
	s[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		s[--len] = tmp % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}

void			posputnbr(uintmax_t n)
{
	uintmax_t digit;

	digit = n % 10;
	if (digit != n)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + digit);
	}
	else
		ft_putchar('0' + digit);
}
