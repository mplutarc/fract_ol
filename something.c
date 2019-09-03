/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:23:34 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 14:38:42 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			some(t_fract *fract, t_complex p)
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
		tmp = p.re;
		p.re = p.re * p.re - p.im * p.im + c.re;
		p.im = 2 * tmp * p.im + c.im;
		c.re = c.re / 2 + p.re;
		c.im = c.im / 2 + p.im;
		if (pow(p.re, 2) + pow(p.im, 2) > 4)
			return (i);
		i++;
	}
	return (0);
}

void		something(t_fract *fract)
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
			new_pxl(p, fract->img, color(fract, some(fract, point)));
			x++;
		}
		y++;
	}
}
