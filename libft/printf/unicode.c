/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:38:23 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/25 15:39:29 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unicode(wchar_t wchar, char **s)
{
	int		i;

	i = 0;
	if (wchar < 0x80)
		(*s)[0] = wchar;
	else if (wchar < 0x800)
	{
		(*s)[0] = 192 + wchar / 64;
		(*s)[1] = 128 + wchar % 64;
	}
	else if (wchar < 0x10000)
	{
		(*s)[0] = 224 + wchar / 4096;
		(*s)[1] = 128 + wchar / 64 % 64;
		(*s)[2] = 128 + wchar % 64;
	}
	else if (wchar < 0x110000)
	{
		(*s)[0] = 240 + wchar / 262144;
		(*s)[1] = 128 + wchar / 4096 % 64;
		(*s)[2] = 128 + wchar / 64 % 64;
		(*s)[3] = 128 + wchar % 64;
	}
}

char	*str_wstr(wchar_t *wchar)
{
	char	*tmp;
	char	*tmp2;
	char	*str;

	str = NULL;
	while (*wchar != L'\0')
	{
		tmp = ft_strnew(5);
		unicode(*wchar, &tmp);
		tmp2 = str;
		str = prtstrjoin(str, tmp);
		wchar++;
		free(tmp);
		if (tmp2 != NULL)
			free(tmp2);
	}
	return (str);
}

wchar_t	*wstr_set(wchar_t *wstr, wchar_t wc, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		wstr[i] = wc;
		i++;
	}
	return (wstr);
}

wchar_t	*ft_wstrdup(wchar_t *ws1)
{
	wchar_t	*wstr;
	int		i;

	i = 0;
	if (ws1 == NULL)
		return (NULL);
	wstr = ft_wstrnew(ft_wstrlen(ws1));
	if (wstr == NULL)
		return (NULL);
	while (*ws1)
		wstr[i++] = *ws1++;
	return (wstr);
}

wchar_t	*wjoinclean(wchar_t **s, t_flags **flags_set, int strleft)
{
	wchar_t	*str;
	wchar_t	*cloud;
	wchar_t	*ret;

	str = *s;
	cloud = wcloudy(flags_set);
	if (strleft)
		ret = ft_wstrjoin(str, cloud);
	else
		ret = ft_wstrjoin(cloud, str);
	if (str)
		free(str);
	if (cloud)
		free(cloud);
	return (ret);
}
