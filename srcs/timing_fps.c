/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:40:25 by dpylypen          #+#    #+#             */
/*   Updated: 2017/05/11 17:00:40 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	time_fps(t_wolf *w)
{
	static int	flag = 0;
	static char	*fps;

	free(fps);
	fps = ft_itoa((int)1.0 / w->frame_time);
	w->old_time = w->time;
	w->time = clock();
	w->frame_time = (w->time - w->old_time) / CLOCKS_PER_SEC;
	w->move_s = w->frame_time * 5.0;
	w->rot_s = w->frame_time * 3.0;
	if (flag == 1)
		mlx_string_put(w->mlx, w->win, 30, 10, 0xFFFFFF, fps);
	flag = 1;
}
