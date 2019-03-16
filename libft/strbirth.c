/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbirth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:27:20 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 11:27:31 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}

void	ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	ft_memset(s, 0, ft_strlen(s));
}

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(s1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	return (str);
}

char	*prtstrdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	return (str);
}
