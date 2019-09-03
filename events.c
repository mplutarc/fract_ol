/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:01:23 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 17:27:54 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		keynumpress(int but, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 82)
		fract->number = 0;
	if (but == 83)
		fract->number = 1;
	if (but == 84)
		fract->number = 2;
	if (but == 85)
		fract->number = 3;
	if (but == 86)
		fract->number = 4;
	if (but == 87)
		fract->number = 5;
	launch_fracts(fract);
	return (0);
}

static int		keyzoom(int but, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 69)
	{
		fract->maxiter += 5;
		launch_fracts(fract);
	}
	else if (but == 78)
	{
		fract->maxiter -= 5;
		launch_fracts(fract);
	}
	return (0);
}

static int		keyfractals(int but, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 38)
		fract->name = 'j';
	else if (but == 46)
		fract->name = 'm';
	else if (but == 1)
		fract->name = 's';
	else if (but == 11)
		fract->name = 'b';
	else if (but == 40)
		fract->name = 'k';
	else if (but == 4)
		fract->name = 'h';
	return (0);
}

int				keypress(int but, void *tmp)
{
	t_fract		*fract;

	fract = (t_fract *)tmp;
	if (but == 53)
		exit(0);
	else if (but == 124)
		fract->offset_x -= 200;
	else if (but == 123)
		fract->offset_x += 200;
	else if (but == 125)
		fract->offset_y -= 200;
	else if (but == 126)
		fract->offset_y += 200;
	else if (but == 43)
		fract->mirror = 1;
	else if (but == 47)
		fract->mirror = 2;
	keyfractals(but, fract);
	keyzoom(but, fract);
	keynumpress(but, fract);
	launch_fracts(fract);
	return (0);
}

int				ft_close(void *param)
{
	(void)param;
	exit(0);
}
