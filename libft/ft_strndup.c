/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:54:31 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/20 16:48:47 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t i)
{
	char	*str;
	size_t	n;

	str = (char*)malloc(sizeof(*str) * (i + 1));
	n = i;
	i = 0;
	if (str)
	{
		while (i < n)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
