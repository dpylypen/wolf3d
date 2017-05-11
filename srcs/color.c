/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:36:28 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 16:36:59 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	set_color_2(t_wolf *w)
{
	if (w->step_x < 0)
		w->color = 0x0000FF;
	else
		w->color = 0xFFFF00;
}

void		set_color(t_wolf *w)
{
	if (w->side == 1)
	{
		if (w->step_y < 0)
			w->color = 0xFF0000;
		else
			w->color = 0x00FF00;
	}
	else
		set_color_2(w);
}
