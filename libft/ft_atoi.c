/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:41:02 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/10 14:59:53 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chknum(char x)
{
	return ((x >= '0' && x <= '9') ? 1 : 0);
}

static int	spac(char x)
{
	if ((x == ' ') || (x == '\t') || (x == '\n')
			|| (x == '\v') || (x == '\f') || (x == '\r'))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	res;
	int	sgn;
	int	i;

	res = 0;
	sgn = 1;
	i = 0;
	while (spac(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((chknum(str[i])) == 0)
		{
			return (sgn * res);
		}
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sgn * res);
}
