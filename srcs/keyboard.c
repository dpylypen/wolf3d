/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:43:10 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 17:22:21 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	control_unit_4(int key, t_wolf *scene)
{
	if (key == 13 || key == 126)
	{
		if (scene->world_map[(int)(scene->pos_x + scene->dir_x * scene->m_s)
	* 24 + (int)scene->pos_y] == 0)
			scene->pos_x += scene->dir_x * scene->m_s;
		if (scene->world_map[(int)(scene->pos_x) * 24 + (int)(scene->pos_y +
	scene->dir_y * scene->m_s)] == 0)
			scene->pos_y += scene->dir_y * scene->m_s;
	}
	if (key == 1 || key == 125)
	{
		if (scene->world_map[(int)(scene->pos_x - scene->dir_x * scene->m_s) *
	24 + (int)(scene->pos_y)] == 0)
			scene->pos_x -= scene->dir_x * scene->m_s;
		if (scene->world_map[(int)(scene->pos_x) * 24 + (int)(scene->pos_y -
	scene->dir_y + scene->m_s)] == 0)
			scene->pos_y -= scene->dir_y * scene->m_s;
	}
}

static void	control_unit_1(int key, t_wolf *scene)
{
	static int flag = 0;

	if (key == 53)
		exit(0);
	if (key == 257)
	{
		if (flag == 0)
		{
			scene->m_s = scene->move_s * 2.5;
			flag = 1;
		}
		else
		{
			scene->m_s = scene->move_s / 2.5;
			flag = 0;
		}
	}
}

static void	control_unit_2(int key, t_wolf *scene)
{
	if (key == 0)
	{
		if (scene->world_map[(int)(scene->pos_x - scene->dir_y *
	scene->move_s) * 24 + (int)(scene->pos_y)] == 0)
			scene->pos_x -= scene->dir_y * scene->move_s / 3;
		if (scene->world_map[(int)(scene->pos_x) * 24 +
	(int)(scene->pos_y + scene->dir_x + scene->move_s)] == 0)
			scene->pos_y += scene->dir_x * scene->move_s / 3;
	}
	if (key == 2)
	{
		if (scene->world_map[(int)(scene->pos_x + scene->dir_y * scene->move_s)
	* 24 + (int)(scene->pos_y)] == 0)
			scene->pos_x += scene->dir_y * scene->move_s / 3;
		if (scene->world_map[(int)(scene->pos_x) * 24 +
	(int)(scene->pos_y - scene->dir_x * scene->move_s)] == 0)
			scene->pos_y -= scene->dir_x * scene->move_s / 3;
	}
}

static void	control_unit_3(int key, t_wolf *scene)
{
	double rot_s;
	double od;
	double op;

	if (key == 124 || key == 123)
	{
		if (key == 124)
			rot_s = -scene->rot_s;
		else
			rot_s = scene->rot_s;
		od = scene->dir_x;
		op = scene->plane_x;
		scene->dir_x = scene->dir_x * cos(rot_s) - scene->dir_y * sin(rot_s);
		scene->dir_y = od * sin(rot_s) + scene->dir_y * cos(rot_s);
		scene->plane_x = scene->plane_x * cos(rot_s) -
	scene->plane_y * sin(rot_s);
		scene->plane_y = op * sin(rot_s) + scene->plane_y * cos(rot_s);
	}
}

int			key_press(int key, void *param)
{
	t_wolf *scene;

	scene = (t_wolf *)param;
	control_unit_1(key, scene);
	control_unit_2(key, scene);
	control_unit_3(key, scene);
	control_unit_4(key, scene);
	engine(scene);
	return (0);
}
