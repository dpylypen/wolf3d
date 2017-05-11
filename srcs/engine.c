/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:37:13 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 18:52:09 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	engine_2(t_wolf *wolf)
{
	wolf->camera_x = 2 * wolf->x / (double)wolf->screen_w - 1;
	wolf->ray_pos_x = wolf->pos_x;
	wolf->ray_pos_y = wolf->pos_y;
	wolf->ray_dir_x = wolf->dir_x + wolf->plane_x * wolf->camera_x;
	wolf->ray_dir_y = wolf->dir_y + wolf->plane_y * wolf->camera_x;
	wolf->map_x = (int)wolf->ray_pos_x;
	wolf->map_y = (int)wolf->ray_pos_y;
	wolf->delta_dist_x = sqrt(1 + (wolf->ray_dir_y * wolf->ray_dir_y) /
	(wolf->ray_dir_x * wolf->ray_dir_x));
	wolf->delta_dist_y = sqrt(1 + (wolf->ray_dir_x * wolf->ray_dir_x) /
	(wolf->ray_dir_y * wolf->ray_dir_y));
	wolf->hit = 0;
	if (wolf->ray_dir_x < 0)
	{
		wolf->step_x = -1;
		wolf->side_dist_x = (wolf->ray_pos_x - wolf->map_x) *
	wolf->delta_dist_x;
	}
	else
	{
		wolf->step_x = 1;
		wolf->side_dist_x = (wolf->map_x + 1.0 - wolf->ray_pos_x) *
	wolf->delta_dist_x;
	}
}

void	engine_3(t_wolf *wolf)
{
	while (wolf->hit == 0)
	{
		if (wolf->side_dist_x < wolf->side_dist_y)
		{
			wolf->side_dist_x += wolf->delta_dist_x;
			wolf->map_x += wolf->step_x;
			wolf->side = 0;
		}
		else
		{
			wolf->side_dist_y += wolf->delta_dist_y;
			wolf->map_y += wolf->step_y;
			wolf->side = 1;
		}
		if (wolf->world_map[wolf->map_x * 24 + wolf->map_y] > 0)
			wolf->hit = 1;
	}
	if (wolf->side == 0)
		wolf->perp_wall_dist = (wolf->map_x - wolf->ray_pos_x +
	(1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else
		wolf->perp_wall_dist = (wolf->map_y - wolf->ray_pos_y +
	(1 - wolf->step_y) / 2) / wolf->ray_dir_y;
}

void	engine_4(t_wolf *wolf)
{
	wolf->line_h = (int)(wolf->screen_h / wolf->perp_wall_dist);
	wolf->draw_start = -wolf->line_h / 2 + wolf->screen_h / 2;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->line_h / 2 + wolf->screen_h / 2;
	if (wolf->draw_end >= wolf->screen_h)
		wolf->draw_end = wolf->screen_h - 1;
	set_color(wolf);
	ver_line(wolf);
}

void	engine(t_wolf *wolf)
{
	ft_memset(wolf->arr, 0, wolf->screen_w * wolf->screen_h * 4);
	wolf->x = -1;
	while (++wolf->x < wolf->screen_w)
	{
		engine_2(wolf);
		if (wolf->ray_dir_y < 0)
		{
			wolf->step_y = -1;
			wolf->side_dist_y = (wolf->ray_pos_y - wolf->map_y) *
	wolf->delta_dist_y;
		}
		else
		{
			wolf->step_y = 1;
			wolf->side_dist_y = (wolf->map_y + 1.0 - wolf->ray_pos_y) *
	wolf->delta_dist_y;
		}
		engine_3(wolf);
		engine_4(wolf);
	}
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	time_fps(wolf);
}
