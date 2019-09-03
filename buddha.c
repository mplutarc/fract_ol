/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:26:43 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 17:36:11 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			brotcolor(int res, int max, t_coord p, t_fract *fract)
{
	int		color;

	res = 0xFF * fract->mass[p.x + p.y * WIDTH] / max;
	if (res > 0)
	{
		res = res > 0xFF ? 0xFF : res;
		res = res < 0 ? 0 : res;
		if (res <= max / 2)
			color = ((255 / (max / 2 - res + 1)) << (2 * 8));
		else
			color = (255 << (2 * 8) | (int)(255 * (res - max / 2 + 1)
				/ (max / 2)) << (1 * 8) | (int)(255 * ((res - max
					/ 2 + 1) / (max / 2))) << (0 * 8));
		new_pxl(p, fract->img, color);
	}
	else
		new_pxl(p, fract->img, 0);
	fract->mass[p.x + p.y * WIDTH] = 0;
}

void			buddhacolor(t_fract *fract)
{
	int			max;
	int			res;
	int			i;
	t_coord		p;

	i = -1;
	max = 0;
	while (++i < HEIGHT * WIDTH)
		if (fract->mass[i] > max)
			max = fract->mass[i];
	p.y = -1;
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
			brotcolor(res, max, p, fract);
	}
}

int				buddha(t_fract *fract, t_complex p)
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
		if (p.re * p.re + p.im * p.im > 4)
			return (i);
		i++;
	}
	return (0);
}

int				brot(t_fract *fract, t_complex p)
{
	int			i;
	double		tmp;
	t_complex	c;
	t_coord		poi;

	i = -1;
	c = p;
	p.re = 0;
	p.im = 0;
	while (++i < fract->maxiter)
	{
		tmp = p.re;
		p.re = p.re * p.re - p.im * p.im + c.re;
		p.im = 2 * tmp * p.im + c.im;
		poi = cocoords(p, fract);
		if (poi.x < WIDTH && poi.y < HEIGHT && poi.x > 0 && poi.y > 0)
			fract->mass[poi.x + poi.y * WIDTH] += 1;
		if (p.re * p.re + p.im * p.im > 4)
			return (i);
	}
	return (0);
}

void			buddhabrot(t_fract *fract)
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
			if (buddha(fract, point))
			{
				brot(fract, point);
			}
			x++;
		}
		y++;
	}
}
