/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   korablik.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:38:24 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 14:25:45 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					korabl(t_fract *fract, t_complex p)
{
	int			i;
	double		tmp;
	t_complex	c;

	i = 0;
	c = p;
	p.re = 0;
	p.im = 0;
	while (i < fract->maxiter)
	{
		p.re = p.re > 0 ? p.re : -p.re;
		p.im = p.im > 0 ? p.im : -p.im;
		tmp = p.re;
		p.re = p.re * p.re - p.im * p.im + c.re;
		p.im = 2 * tmp * p.im + c.im;
		if (p.re * p.re + p.im * p.im > 4)
			return (i);
		i++;
	}
	return (0);
}

void				korablik(t_fract *fract)
{
	t_coord		p;
	t_complex	point;
	int			x;
	int			y;
	int			i;

	y = fract->ymin - 1;
	while (y < fract->ymax)
	{
		p.y = y;
		x = 0;
		while (x < WIDTH)
		{
			p.x = x;
			point = (coords(p, fract));
			new_pxl(p, fract->img, color(fract, korabl(fract, point)));
			x++;
		}
		y++;
	}
}
