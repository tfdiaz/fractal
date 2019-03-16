/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:04:27 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 11:04:36 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (b[i] != '\0')
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (match((haystack + i), needle))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len != 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i] != '\0')
			i++;
		if (needle[i] == '\0' && i <= len)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

char		*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char		*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
