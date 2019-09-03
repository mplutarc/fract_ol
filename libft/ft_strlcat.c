/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:48:26 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/12 16:21:10 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && (i + j + 1 < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size <= i)
		return (size + ft_strlen(src));
	return (i + ft_strlen(src));
}
