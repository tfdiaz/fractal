/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:57:59 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 10:58:01 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sgn;
	int	digit;

	sgn = 1;
	if (n < 0)
		sgn = -1;
	digit = n % 10;
	if (n != digit)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + digit * sgn, fd);
	}
	else
	{
		if (sgn < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' + digit * sgn, fd);
	}
}

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
