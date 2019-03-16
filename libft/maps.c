/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:50:41 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 19:50:44 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*snew;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	snew = ft_strnew(len);
	if (snew == NULL)
		return (NULL);
	while (i < (int)len)
	{
		snew[i] = f(s[i]);
		i++;
	}
	return (snew);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*snew;

	i = 0;
	if (s == NULL)
		return (NULL);
	snew = ft_strnew(ft_strlen(s));
	if (snew == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = f(i, s[i]);
		i++;
	}
	return (snew);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*lt;

	while (lst)
	{
		lt = f(lst);
		cpy = lt;
		while (lst->next)
		{
			lst = lst->next;
			if (!(lt->next = f(lst)))
			{
				free(lt->next);
				return (NULL);
			}
			lt = lt->next;
		}
		return (cpy);
	}
	return (NULL);
}
