/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:44:07 by dpylypen          #+#    #+#             */
/*   Updated: 2017/05/11 17:01:55 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include "math.h"
# include "mouse.h"
# include "keyboard.h"
# include <time.h>
# include <fcntl.h>

typedef struct	s_wolf
{
	int			map_width;
	int			map_height;
	int			*world_map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		frame_time;
	void		*mlx;
	void		*win;
	void		*img;
	int			endians;
	int			bits;
	int			size_line;
	int			*arr;
	int			screen_w;
	int			screen_h;
	double		camera_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			x;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			color;
	double		move_s;
	double		rot_s;
	double		m_s;
	double		old_mouse;
}				t_wolf;

t_wolf			init_wolf(void);
void			start_win(void);
void			set_color(t_wolf *w);
void			engine(t_wolf *wolf);
void			ver_line(t_wolf *wolf);
void			time_fps(t_wolf *w);
#endif
