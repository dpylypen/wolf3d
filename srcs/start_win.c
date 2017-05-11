/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:39:13 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/26 17:39:59 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		start_win(void)
{
	t_wolf wolf;

	wolf = init_wolf();
	engine(&wolf);
	mlx_hook(wolf.win, 2, 0, key_press, &wolf);
	mlx_hook(wolf.win, 6, 5, mouse_move, &wolf);
	mlx_hook(wolf.win, 17, 0, x, &wolf);
	mlx_loop(wolf.mlx);
}
