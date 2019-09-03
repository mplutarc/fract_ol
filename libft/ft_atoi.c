/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:16 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/20 14:18:51 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	new;
	int			n;

	i = 0;
	new = 0;
	n = 1;
	while ((ft_isspace(str[i])) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		new = new * 10 + str[i++] - '0';
		if (new < 0)
			return ((n == 1) ? -1 : 0);
	}
	return (new * n);
}
