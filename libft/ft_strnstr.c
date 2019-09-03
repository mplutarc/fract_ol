/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:06:49 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/27 00:12:47 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char *)haystack;
	if (!*needle)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return (str + i);
			}
		}
		i++;
	}
	return (NULL);
}
