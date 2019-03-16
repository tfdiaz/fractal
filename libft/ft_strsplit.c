/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:05:02 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/12 11:39:21 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	delmc(const char *s, char c)
{
	int	wd;
	int	flag;

	flag = 0;
	wd = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			wd++;
		}
		s++;
	}
	return (wd);
}

static int	wdlen(const char *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		wd;
	int		id;

	id = 0;
	if (s == NULL)
		return (NULL);
	wd = delmc(s, c);
	if ((ret = (char**)malloc(sizeof(char*) * (delmc(s, c) + 1))) == NULL)
		return (NULL);
	while (wd--)
	{
		while (*s == c && *s != '\0')
			s++;
		if ((ret[id] = ft_strsub(s, 0, wdlen(s, c))) == NULL)
		{
			while (--id >= 0)
				free(ret[id]);
			return (NULL);
		}
		s = s + wdlen(s, c);
		id++;
	}
	ret[id] = NULL;
	return (ret);
}
