/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:39:21 by dpylypen          #+#    #+#             */
/*   Updated: 2017/05/11 16:59:35 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	er_ex(void)
{
	ft_putstr("Error_map");
	exit(EXIT_FAILURE);
}

void		base_check(int fd, t_wolf *wolf)
{
	int		len_x;
	int		tmp_len_x;
	char	symb;
	int		i;

	i = -1;
	len_x = 0;
	tmp_len_x = 0;
	while (read(fd, &symb, 1) == 1 && symb != '\n')
	{
		len_x++;
		tmp_len_x++;
		while (read(fd, &symb, 1) == 1 && symb != '\n')
		{
			len_x++;
			tmp_len_x++;
		}
		if (len_x != tmp_len_x / (wolf->map_height + 1))
			er_ex();
		wolf->map_width = len_x;
		len_x = 0;
		wolf->map_height++;
		i = -1;
	}
}

void		make_arr(t_wolf *wolf, int fd)
{
	int		i;
	int		j;
	char	symb;

	i = 0;
	wolf->world_map = (int *)malloc(sizeof(int) *
	(wolf->map_height * wolf->map_width));
	while (read(fd, &symb, 1) == 1)
	{
		j = 0;
		while (j != wolf->map_width)
		{
			if (!(symb == '0' || symb == '1' || symb == '\n'))
				er_ex();
			if ((j == 0 || j == wolf->map_width - 1 || i == 0 ||
	i == wolf->map_height - 1) && symb != '1')
				er_ex();
			wolf->world_map[(i * wolf->map_width) + j] = symb - '0';
			read(fd, &symb, 1);
			j++;
		}
		i++;
	}
}

void		read_map(char *map, t_wolf *wolf)
{
	int		fd;
	int		fd2;

	if ((fd = open(map, O_RDONLY)) < 1)
		er_ex();
	if ((fd2 = open(map, O_RDONLY)) < 1)
		er_ex();
	base_check(fd, wolf);
	close(fd);
	if (wolf->map_width < 3 && wolf->map_height < 3)
		er_ex();
	make_arr(wolf, fd2);
	close(fd2);
}

t_wolf		init_wolf(void)
{
	t_wolf wolf;

	read_map("./map", &wolf);
	wolf.pos_x = 15;
	wolf.pos_y = 11;
	wolf.dir_x = -1;
	wolf.dir_y = 0;
	wolf.plane_x = 0;
	wolf.plane_y = 0.66;
	wolf.time = 0;
	wolf.old_time = 0;
	wolf.hit = 0;
	wolf.screen_w = 1200;
	wolf.screen_h = 800;
	wolf.mlx = mlx_init();
	wolf.win = mlx_new_window(wolf.mlx, wolf.screen_w, wolf.screen_h, "Wolf3D");
	wolf.img = mlx_new_image(wolf.mlx, wolf.screen_w, wolf.screen_h);
	wolf.arr = (int *)mlx_get_data_addr(wolf.img, &wolf.bits, &wolf.size_line,
	&wolf.endians);
	wolf.move_s = 0.07;
	wolf.m_s = 0.07;
	wolf.rot_s = 0.05;
	wolf.old_mouse = 400;
	return (wolf);
}
