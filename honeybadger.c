/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   honeybadger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:47:05 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 14:25:22 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					honey(t_fract *fract, t_complex p)
{
	int			i;
	double		tmp;

	i = 0;
	while (i < fract->maxiter)
	{
		if (fract->mirror == 1)
			p.im = p.im > 0 ? p.im : -p.im;
		else if (fract->mirror == 2)
			p.re = p.re > 0 ? p.re : -p.re;
		tmp = p.re;
		p.re = p.re * p.re - p.im * p.im + fract->fractol.c_re;
		p.im = 2 * tmp * p.im + fract->fractol.c_im;
		if (p.re * p.re + p.im * p.im > 4)
			return (i);
		i++;
	}
	return (0);
}

void				honeybadger(t_fract *fract)
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
			new_pxl(p, fract->img, color(fract, honey(fract, point)));
			x++;
		}
		y++;
	}
}
