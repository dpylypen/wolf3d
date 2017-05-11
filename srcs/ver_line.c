/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:41:01 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 17:42:22 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ver_line(t_wolf *wolf)
{
	int y;

	if (wolf->draw_end < wolf->draw_start)
	{
		wolf->draw_start += wolf->draw_end;
		wolf->draw_end = wolf->draw_start - wolf->draw_end;
		wolf->draw_start -= wolf->draw_end;
	}
	if (wolf->draw_end < 0 || wolf->draw_start >= wolf->screen_h ||
	wolf->x < 0 || wolf->x >= wolf->screen_w)
		return ;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	if (wolf->draw_end >= wolf->screen_w)
		wolf->draw_end = wolf->screen_h - 1;
	y = wolf->draw_start - 1;
	while (++y <= wolf->draw_end)
		wolf->arr[y * wolf->size_line / 4 + wolf->x] = wolf->color;
}
