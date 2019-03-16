/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vects.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:40:44 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/16 19:40:49 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vect2str(t_vect *vect)
{
	char *s;

	if (vect == NULL)
		return (NULL);
	s = ft_strnew(vect->ctsize);
	ft_memcpy(s, vect->content, vect->ctsize);
	vect_free(&vect);
	return (s);
}

t_vect	*str2vect(t_vect *vect, char const *s)
{
	if (vect == NULL)
		vect = vect_new();
	vect = vect_add(vect, s, ft_strlen(s));
	return (vect);
}

t_vect	*vect_add(t_vect *vect, const void *content, size_t content_size)
{
	void	*new;
	void	*tmp;

	if (vect->cap < vect->ctsize + content_size)
	{
		while (vect->cap < vect->ctsize + content_size)
			vect->cap *= 2;
		new = ft_memalloc(vect->cap);
		tmp = vect->content;
		vect->content = ft_memmove(new, vect->content, vect->ctsize);
		if (tmp != NULL)
			free(tmp);
	}
	ft_memcpy(vect->content + vect->ctsize, content, content_size);
	vect->ctsize += content_size;
	return (vect);
}

void	vect_free(t_vect **vect)
{
	if (vect == NULL)
		return ;
	free((*vect)->content);
	free(*vect);
	*vect = NULL;
}

t_vect	*vect_new(void)
{
	t_vect	*vect;

	vect = (t_vect*)malloc(sizeof(t_vect));
	if (!vect)
		return (NULL);
	vect->cap = CAP_SIZE;
	vect->ctsize = 0;
	vect->content = ft_memalloc(CAP_SIZE);
	return (vect);
}
