/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:31:44 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/27 00:20:58 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	un_nb;
	int				d;

	if (n < 0)
	{
		un_nb = n * (-1);
		ft_putchar('-');
	}
	else
		un_nb = n;
	d = 1;
	while (un_nb / d / 10 > 0)
	{
		d = d * 10;
	}
	while (d >= 1)
	{
		ft_putchar(48 + un_nb / d % 10);
		d = d / 10;
	}
}
