/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:42:26 by mplutarc          #+#    #+#             */
/*   Updated: 2019/04/16 15:48:12 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un_nb;
	int				d;

	if (n < 0)
	{
		un_nb = n * (-1);
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd((48 + un_nb / d % 10), fd);
		d = d / 10;
	}
}
