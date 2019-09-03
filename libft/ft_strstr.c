/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:29:04 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/29 00:48:14 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)haystack;
	if (!*needle)
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j])
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
