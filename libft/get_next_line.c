/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:27:19 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/15 17:53:45 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd	*fd_lst_new(int fd)
{
	t_fd		*fd_new;

	fd_new = (t_fd*)ft_memalloc(sizeof(t_fd));
	if (fd_new == NULL)
		return (NULL);
	fd_new->next = NULL;
	fd_new->fd = fd;
	return (fd_new);
}

static char	*find_buff(t_fd **fd_lst, int fd)
{
	t_fd	*tmp;

	if ((*fd_lst) == NULL)
	{
		if ((*fd_lst = fd_lst_new(fd)))
			return ((*fd_lst)->buff);
		return (NULL);
	}
	tmp = (*fd_lst);
	while ((tmp) != NULL)
	{
		if (tmp->fd == fd)
			return (tmp->buff);
		tmp = tmp->next;
	}
	tmp = fd_lst_new(fd);
	if (fd_lst || tmp)
	{
		tmp->next = *fd_lst;
		*fd_lst = tmp;
	}
	return ((tmp)->buff);
}

static int	find_nline(char *buff, char **line, t_vect *vect)
{
	size_t		i;
	char		*str;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			str = ft_strnew(i + vect->ctsize);
			str = ft_strcpy(str, (char *)(vect->content));
			str = ft_strncat(str, buff, i);
			ft_memmove(buff, buff + i + 1, BUFF_SIZE - i);
			*line = str;
			vect_free(&vect);
			return (1);
		}
		i++;
	}
	vect = vect_add(vect, buff, ft_strlen(buff));
	ft_memmove(buff, buff + BUFF_SIZE, 1);
	return (0);
}

static void	fd_remove(t_fd **fd_lst, int fd)
{
	t_fd	*tmp;
	t_fd	*rmv;

	if (*fd_lst == NULL)
		return ;
	if ((*fd_lst)->next == NULL && (*fd_lst)->fd == fd)
	{
		free(*fd_lst);
		*fd_lst = NULL;
	}
	tmp = *fd_lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->fd == fd)
		{
			rmv = tmp->next;
			tmp->next = tmp->next->next;
			free(rmv);
			return ;
		}
		tmp = tmp->next;
	}
}

int			get_next_line(const int fd, char **line)
{
	t_vect		*vect;
	static t_fd	*fd_lst;
	int			numred;
	char		*buff;

	numred = 1;
	if ((buff = find_buff(&fd_lst, fd)) == NULL)
		return (-1);
	vect = vect_new();
	while (numred > 0)
	{
		if (buff[0] == '\0')
		{
			numred = read(fd, buff, BUFF_SIZE);
			if (numred < 0)
				return (numred);
			buff[numred] = '\0';
		}
		if (find_nline(buff, line, vect) == 1)
			return (1);
	}
	*line = vect2str(vect);
	fd_remove(&fd_lst, fd);
	return ((*line)[0] != '\0') ? (1) : (0);
}
