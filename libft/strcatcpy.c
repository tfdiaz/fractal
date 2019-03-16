/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcatcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:19:22 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 11:21:33 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	while (j < n && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*e_dst;
	const char	*s_src;
	size_t		n;
	size_t		dlen;

	n = dstsize;
	s_src = src;
	e_dst = dst;
	while (n-- != 0 && *e_dst != '\0')
		e_dst++;
	dlen = e_dst - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*s_src != '\0')
	{
		if (n != 1)
		{
			*e_dst++ = *s_src;
			n--;
		}
		s_src++;
	}
	*e_dst = '\0';
	return (dlen + (s_src - src));
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	while (i < len)
	{
		if (i > slen)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
