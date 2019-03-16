/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:39:17 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 11:39:25 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
		ret[i] = *s++;
	ret[i] = '\0';
	return (ret);
}

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + (c - 'A'));
	return (c);
}

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ('A' + (c - 'a'));
	return (c);
}

void	prtup_str(char **s)
{
	int i;

	i = 0;
	while ((*s)[i] != '\0')
	{
		if ((*s)[i] >= 'a' && (*s)[i] <= 'z')
			(*s)[i] -= 32;
		i++;
	}
}
