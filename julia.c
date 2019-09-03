/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:25:40 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/28 19:12:30 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	jcoords(t_coord point, t_fract *fract)
{
	t_complex	p;

	p.re = (double)(point.x - (WIDTH / 2) + fract->offset_x) / ((HEIGHT / 2)
						* fract->scale) * 1.5;
	p.im = (double)(point.y - (HEIGHT / 2) + fract->offset_y) / ((HEIGHT / 2)
						* fract->scale);
	return (p);
}

int					juli(t_fract *fract, t_complex p)
{
	int			i;
	double		tmp;

	i = 0;
	while (i < fract->maxiter)
	{
		tmp = p.re;
		p.re = (p.re * p.re - p.im * p.im) + fract->fractol.c_re;
		p.im = 2 * tmp * p.im + fract->fractol.c_im;
		if (p.re * p.re + p.im * p.im > 4)
			return (i);
		i++;
	}
	return (0);
}

void				julia(t_fract *fract)
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
			point = (jcoords(p, fract));
			new_pxl(p, fract->img, color(fract, juli(fract, point)));
			x++;
		}
		y++;
	}
}
