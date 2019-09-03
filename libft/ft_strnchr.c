/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:28:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/23 14:28:26 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t end)
{
	char	*str;

	str = (char *)s;
	while (*str != c || end)
	{
		if (*str == '\0')
			return (NULL);
		str++;
		end--;
	}
	return (str);
}
