/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:07:48 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 20:07:51 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tnew;

	tnew = (t_list*)malloc(sizeof(t_list));
	if (tnew == NULL)
		return (NULL);
	tnew->next = NULL;
	if (content == NULL || !content_size)
	{
		tnew->content = NULL;
		tnew->content_size = 0;
		return (tnew);
	}
	tnew->content = malloc(content_size);
	if (tnew->content == NULL)
	{
		free(tnew);
		return (NULL);
	}
	ft_memcpy((tnew->content), content, content_size);
	tnew->content_size = content_size;
	return (tnew);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst || new)
	{
		new->next = *alst;
		*alst = new;
	}
}
