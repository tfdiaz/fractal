/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:12:32 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 20:12:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putstr(char const *s)
{
	while (*s)
		write(1, s++, 1);
}

void	prtputstr(char const *s)
{
	while (*s)
	{
		if (*s == 7)
			write(1, "\0", 1);
		else
			write(1, s, 1);
		s++;
	}
}

void	ft_putnbr(int n)
{
	int	sgn;
	int digit;

	sgn = 1;
	if (n < 0)
		sgn = -1;
	digit = n % 10;
	if (digit != n)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + digit * sgn);
	}
	else
	{
		if (sgn < 0)
			ft_putchar('-');
		ft_putchar('0' + digit * sgn);
	}
}
