/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:24:04 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 17:38:50 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			x(void)
{
	exit(0);
}

static void	mouse_move_2(t_wolf *scene, double cof_rot_s, int x)
{
	double od;
	double op;

	od = scene->dir_x;
	op = scene->plane_x;
	scene->dir_x = scene->dir_x * cos(cof_rot_s) - scene->dir_y *
	sin(cof_rot_s);
	scene->dir_y = od * sin(cof_rot_s) + scene->dir_y * cos(cof_rot_s);
	scene->plane_x = scene->plane_x * cos(cof_rot_s) - scene->plane_y *
	sin(cof_rot_s);
	scene->plane_y = op * sin(cof_rot_s) + scene->plane_y * cos(cof_rot_s);
	scene->old_mouse = x;
}

int			mouse_move(int x, int y, void *param)
{
	t_wolf *scene;
	double cof_rot_s;

	scene = (t_wolf*)param;
	y = 0;
	if (x)
	{
		if (x > scene->old_mouse)
		{
			cof_rot_s = -scene->rot_s * fabs(scene->old_mouse - x) / 5;
			scene->old_mouse = x;
		}
		else
		{
			cof_rot_s = scene->rot_s * fabs(scene->old_mouse - x) / 5;
			scene->old_mouse = x;
		}
		mouse_move_2(scene, cof_rot_s, x);
	}
	engine(scene);
	return (0);
}
