/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:46:26 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/11 06:15:24 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	if (len)
		len--;
	else
		return (b);
	while (len > 0)
	{
		*(unsigned char*)(b + len) = c;
		len--;
	}
	*(unsigned char*)(b + len) = c;
	return (b);
}
