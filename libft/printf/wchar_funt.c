/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_funt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:40:43 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/25 21:40:46 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *wchar)
{
	size_t	i;

	i = 0;
	while (*(wchar++) != L'\0')
		i++;
	return (i);
}

wchar_t	*ft_wstrjoin(wchar_t *ws1, wchar_t *ws2)
{
	size_t	ltot;
	wchar_t	*wchar;

	if (ws1 == NULL && ws2 != NULL)
		return (ft_wstrdup(ws2));
	if (ws2 == NULL && ws1 != NULL)
		return (ft_wstrdup(ws1));
	ltot = ft_wstrlen(ws1) + ft_wstrlen(ws2) + 1;
	if ((wchar = (wchar_t*)malloc(sizeof(wchar_t) * ltot)) == NULL)
		return (NULL);
	ft_wstrcpy(wchar, ws1);
	ft_wstrcat(wchar, ws2);
	return (wchar);
}

wchar_t	*ft_wstrcpy(wchar_t *dst, wchar_t *src)
{
	int	i;

	i = 0;
	while (src[i] != L'\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = L'\0';
	return (dst);
}

wchar_t	*ft_wstrcat(wchar_t *ws1, wchar_t *ws2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ws1[i] != L'\0')
		i++;
	while (ws2[j] != L'\0')
	{
		ws1[i + j] = ws2[j];
		j++;
	}
	ws1[i + j] = L'\0';
	return (ws1);
}

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;

	wstr = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (wstr == NULL)
		return (NULL);
	wstr_set(wstr, L'\0', size + 1);
	return (wstr);
}
