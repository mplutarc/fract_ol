/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:44:57 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/26 17:20:31 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	length(int nb)
{
	size_t len;

	len = (nb == 0) ? 1 : 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	len--;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	len = length(n) + 1 + neg;
	res = ft_strnew(sizeof(char) * (len));
	if (!res)
		return (NULL);
	len--;
	while (len + 1)
	{
		if (neg)
			res[len] = -1 * (n % 10) + '0';
		else
			res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
