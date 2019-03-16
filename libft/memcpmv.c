/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpmv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:59:28 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 19:59:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ssrc;
	unsigned char	*ddst;
	size_t			i;

	i = -1;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	if (ssrc < ddst)
	{
		while ((int)--len >= 0)
		{
			*(ddst + len) = *(ssrc + len);
		}
	}
	else
	{
		while (++i < len)
		{
			*(ddst + i) = *(ssrc + i);
		}
	}
	return (ddst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned char	ch;
	size_t			i;

	i = 0;
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if (ch == c_src[i])
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*str == ch)
			return ((void*)str);
		str++;
		i++;
	}
	return (NULL);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while ((int)n > 0 && *st1 == *st2)
	{
		st1++;
		st2++;
		n--;
	}
	if ((int)n == 0)
		return (0);
	else
		return (*st1 - *st2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	i = 0;
	c_dst = (char*)dst;
	c_src = (char*)src;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (c_dst);
}
