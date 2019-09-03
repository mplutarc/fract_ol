/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:27:59 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/24 17:51:15 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*find_fd(int fd, t_list **list)
{
	t_list	*tmp;

	if (!*list)
	{
		*list = ft_lstnew("\0", fd);
		return (*list);
	}
	tmp = *list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		if (!(tmp->next))
		{
			tmp->next = ft_lstnew("\0", fd);
			return (tmp->next);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

static char		*ft_strnjoin(char *sc1, char *s2, int len)
{
	char	*str;
	int		nbr;
	char	*d;
	char	*s1;

	s1 = sc1;
	nbr = ft_strlen(s1) + ++len;
	str = ft_strnew(nbr);
	d = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	free((void *)sc1);
	return (d);
}

static int		find_n_cut(t_list *list, char **line)
{
	int		i;
	void	*to_free;

	i = 0;
	while (((char *)list->content)[i] && ((char *)list->content)[i] != '\n')
		++i;
	*line = ft_strndup(list->content, i);
	if (((char *)list->content)[i] == '\n')
		++i;
	to_free = list->content;
	list->content = ft_strdup(list->content + i);
	free(to_free);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	tmp = find_fd(fd, &list);
	while (!ft_strchr(tmp->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		tmp->content = ft_strnjoin(tmp->content, buf, ret);
	ret = find_n_cut(tmp, line);
	if (ret > 0)
		return (1);
	return (0);
}
