/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:29:21 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 15:49:07 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				new_pxl(t_coord p, t_img *img, unsigned int color)
{
	if (p.x < 0 || p.y < 0 || p.x >= img->width || p.y >= img->height)
		return ;
	*(int *)(img->data_ptr + p.x * img->bpp + p.y *
				img->width * img->bpp) = color;
}

int					mandel(t_fract *fract, t_complex p)
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

void				mandelbrot(t_fract *fract)
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
			new_pxl(p, fract->img, color(fract, mandel(fract, point)));
			x++;
		}
		y++;
	}
}
