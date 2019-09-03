/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:34:21 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/15 16:07:56 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (src < dst)
	{
		i = len;
		while (i--)
		{
			ds[i] = sr[i];
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			ds[i] = sr[i];
	}
	return (dst);
}
