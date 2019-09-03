/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:54:47 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/09 21:09:15 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**words(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	start;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(res[j] = ft_strsub(s, start, i - start)))
				return (ft_free(res, j));
			j++;
			res[j] = NULL;
		}
	}
	res[j] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	len;
	size_t	i;
	size_t	count;

	len = 0;
	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
			len++;
	}
	count = ft_count_words(s, c);
	res = (char **)ft_strnew(sizeof(char *) * (len + count));
	if (res)
	{
		res = words(s, c, res);
		return (res);
	}
	else
		return (NULL);
}
