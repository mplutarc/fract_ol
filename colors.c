/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:15:36 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 16:09:38 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		colorcolor(t_fract *fract, int iter, t_rgb rgb)
{
	double	t;

	t = (double)iter / (double)fract->maxiter;
	if (fract->number == 3)
	{
		rgb.red = (int)(3 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(49 * pow((1 - t), 2) * pow(t, 2) * 255);
		rgb.blue = (int)(5 * pow((1 - t), 3) * t * 255);
	}
	else if (fract->number == 4)
	{
		rgb.red = (int)(2 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(25 * pow((1 - t), 2) * pow(t, 2) * 255);
		rgb.blue = (int)(2 * pow((1 - t), 3) * t * 255);
	}
	else if (fract->number == 5)
	{
		rgb.red = (int)(50 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(50 * (1 - t) * pow(t, 3) * 255);
		rgb.blue = (int)(50 * (1 - t) * pow(t, 3) * 255);
	}
	return ((rgb.red << 16) + (rgb.green << 8) + rgb.blue);
}

int		color(t_fract *fract, int iter)
{
	double	t;
	t_rgb	rgb;

	t = (double)iter / (double)fract->maxiter;
	if (fract->number == 0)
	{
		rgb.red = (int)(19 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(6 * pow((1 - t), 2) * pow(t, 2) * 255);
		rgb.blue = (int)(2 * pow((1 - t), 3) * t * 255);
	}
	else if (fract->number == 1)
	{
		rgb.red = (int)(20 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		rgb.blue = (int)(25 * pow((1 - t), 3) * t * 255);
	}
	else if (fract->number == 2)
	{
		rgb.red = (int)(4 * (1 - t) * pow(t, 3) * 255);
		rgb.green = (int)(5 * pow((1 - t), 2) * pow(t, 2) * 255);
		rgb.blue = (int)(9 * pow((1 - t), 3) * t * 255);
	}
	return (colorcolor(fract, iter, rgb));
}
