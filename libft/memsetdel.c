/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:55:51 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 19:55:54 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(sizeof(void*) * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*cpy;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	cpy = (char*)b;
	while (i < len)
	{
		cpy[i] = ch;
		i++;
	}
	return (cpy);
}

void	ft_memdel(void **ap)
{
	if (ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char*)s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
