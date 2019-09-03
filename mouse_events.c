/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:05:55 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/28 19:54:58 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mousepress(int but, int x, int y, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 1)
	{
		fract->flags = 1;
		fract->mouse.x = x;
		fract->mouse.y = y;
		launch_fracts(fract);
	}
	if (but == 2)
	{
		fract->flags = 2;
		fract->mouse.x = x;
		fract->mouse.y = y;
		launch_fracts(fract);
	}
	return (0);
}

int		mousezoom(int but, int x, int y, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 53)
		exit(0);
	else if (but == 4)
	{
		fract->offset_x += ((x - WIDTH / 2 + fract->offset_x) * 0.1);
		fract->offset_y += ((y - HEIGHT / 2 + fract->offset_y) * 0.1);
		fract->scale *= 1.1;
		launch_fracts(fract);
	}
	else if (but == 5)
	{
		fract->offset_x -= ((x - WIDTH / 2 + fract->offset_x) * 0.1);
		fract->offset_y -= ((y - HEIGHT / 2 + fract->offset_y) * 0.1);
		fract->scale *= 0.9;
		launch_fracts(fract);
	}
	mousepress(but, x, y, fract);
	return (0);
}

int		mousemove(int x, int y, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (fract->flags == 1)
	{
		fract->fractol.c_im += (x - fract->mouse.x) / 500.f;
		fract->fractol.c_re += (y - fract->mouse.y) / 500.f;
	}
	if (fract->flags == 2)
	{
		fract->offset_x -= (x - WIDTH / 2 + fract->offset_x);
		fract->offset_y -= (y - HEIGHT / 2 + fract->offset_y);
	}
	fract->mouse.x = x;
	fract->mouse.y = y;
	launch_fracts(fract);
	return (0);
}

int		mouserelease(int but, int x, int y, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 1 || but == 2)
		fract->flags = 0;
	x = 0;
	y = 0;
	launch_fracts(fract);
	return (0);
}
