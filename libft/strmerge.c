/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmerge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:33:09 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 11:33:18 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ltot;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ltot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((str = (char*)malloc(sizeof(char) * ltot)) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*prtstrjoin(char *s1, char *s2)
{
	size_t	ltot;
	char	*str;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	ltot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((str = (char*)malloc(sizeof(char) * ltot)) == NULL)
		return (NULL);
	if (*s1 == '0' && *s2 == '-')
	{
		s2++;
		*str++ = '-';
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str--;
		return (str);
	}
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (len--)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
