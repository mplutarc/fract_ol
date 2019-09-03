/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:01:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/22 19:04:35 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	a = (t_list *)ft_memalloc(sizeof(t_list));
	if (a)
	{
		if (!content)
		{
			a->content = NULL;
			a->content_size = 0;
		}
		else
		{
			if (!(a->content = ft_memalloc(content_size)))
			{
				free(a);
				return (NULL);
			}
			ft_memcpy(a->content, content, content_size);
			a->content_size = content_size;
		}
		a->next = NULL;
		return (a);
	}
	else
		return (NULL);
}
