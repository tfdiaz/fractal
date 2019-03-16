/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_cws.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:48:29 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/01 14:49:05 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*joinclean(char **s, t_flags **f_set, int strleft)
{
	char *str;
	char *cloud;
	char *ret;

	str = *s;
	cloud = cloudy(f_set);
	if (strleft)
		ret = prtstrjoin(str, cloud);
	else
		ret = prtstrjoin(cloud, str);
	if (str)
		free(str);
	if (cloud)
		free(cloud);
	return (ret);
}

void	prt_str(va_list ap, t_flags **f_set, t_vect **vect)
{
	char *str;

	str = ft_strdup(va_arg(ap, const char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if ((*f_set)->preclen < (int)ft_strlen(str) && (*f_set)->preclen != 0)
		str[((*f_set)->preclen)] = '\0';
	(*f_set)->padlen -= ft_strlen(str);
	if ((*f_set)->leftjust)
		str = joinclean(&str, f_set, 1);
	else
		str = joinclean(&str, f_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void	prt_c(va_list ap, t_flags **f_set, t_vect **vect)
{
	char c;
	char *str;

	c = va_arg(ap, int);
	if (c == 0)
		c = 7;
	str = ft_strnew(1);
	str[0] = c;
	if ((*f_set)->preclen < (int)ft_strlen(str) && (*f_set)->preclen != 0)
		str[((*f_set)->preclen)] = '\0';
	(*f_set)->padlen -= ft_strlen(str);
	if ((*f_set)->leftjust)
		str = joinclean(&str, f_set, 1);
	else
		str = joinclean(&str, f_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void	prt_wstr(va_list ap, t_flags **f_set, t_vect **vect)
{
	wchar_t	*wstr;
	char	*str;

	wstr = ft_wstrdup(va_arg(ap, wchar_t*));
	if (wstr == NULL)
		wstr = ft_wstrdup(L"(null)");
	if ((*f_set)->preclen < (int)ft_wstrlen(wstr) && (*f_set)->preclen != 0)
		wstr[((*f_set)->preclen)] = '\0';
	(*f_set)->padlen -= ft_wstrlen(wstr);
	if ((*f_set)->leftjust)
		wstr = wjoinclean(&wstr, f_set, 1);
	else
		wstr = wjoinclean(&wstr, f_set, 0);
	str = str_wstr(wstr);
	vect_add((*vect), str, ft_wstrlen(wstr));
	free(str);
	free(wstr);
}

void	prt_percent(va_list ap, t_flags **f_set, t_vect **vect)
{
	char *str;

	(void)ap;
	str = ft_strdup("%");
	if (str == NULL)
		str = ft_strdup("(null)");
	if ((*f_set)->preclen < (int)ft_strlen(str) && (*f_set)->preclen != 0)
		str[((*f_set)->preclen)] = '\0';
	(*f_set)->padlen -= ft_strlen(str);
	if ((*f_set)->leftjust)
		str = joinclean(&str, f_set, 1);
	else
		str = joinclean(&str, f_set, 0);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}
