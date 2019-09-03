/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:34:02 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/20 18:18:56 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atol(const char *str)
{
	int				i;
	long long int	result;
	long long int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while ((ft_isspace(str[i])) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			exit(0);
		if (str[i] < 48 || 57 < str[i])
			return (result * neg);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (result * neg);
}
