/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clouds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:42:24 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 17:42:37 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*joinfree(char *s, char **s2)
{
	char	*ret;

	ret = prtstrjoin(s, *s2);
	free(*s2);
	return (ret);
}

char	*cloudy(t_flags **f_set)
{
	char		*str;
	intmax_t	x;

	x = (*f_set)->padlen;
	if ((*f_set)->padlen <= 0)
		return (NULL);
	if ((*f_set)->zeropad && (*f_set)->plus && !((*f_set)->leftjust))
		(*f_set)->padlen--;
	if ((*f_set)->space)
		(*f_set)->padlen--;
	str = ft_strnew((*f_set)->padlen + 1);
	if ((*f_set)->zeropad && !((*f_set)->leftjust))
		str = ft_memset(str, '0', (*f_set)->padlen);
	else
		str = ft_memset(str, ' ', (*f_set)->padlen);
	if ((*f_set)->zeropad && (*f_set)->plus && !((*f_set)->leftjust))
		str = prtstrjoin("+", str);
	return (str);
}

wchar_t	*wcloudy(t_flags **f_set)
{
	wchar_t		*wstr;
	intmax_t	x;

	x = (*f_set)->padlen;
	if ((*f_set)->padlen <= 0)
		return (NULL);
	wstr = ft_wstrnew((*f_set)->padlen + 1);
	wstr = wstr_set(wstr, L' ', (*f_set)->padlen);
	return (wstr);
}
