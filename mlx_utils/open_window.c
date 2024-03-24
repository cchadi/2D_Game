/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:02:50 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 14:14:47 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	ft_initialisation(t_texture t)
{
	t.door_path = "./texture/door.xpm";
	t.wall_path = "./texture/wall.xpm";
	t.player_path = "./texture/player.xpm";
	t.space_path = "./texture/background.xpm";
	t.collect_path = "./texture/collectable.xpm";
	return (t);
}

int	ft_close(t_texture *t)
{
	mlx_destroy_window(t->mlx, t->window);
	exit(0);
}

int	manage_event(int key, t_texture *t)
{
	if (key == 53)
		ft_exit(t);
	else if (key == 126 || key == 13)
		move_up(t);
	else if (key == 125 || key == 1)
		move_down(t);
	else if (key == 124 || key == 2)
		move_right(t);
	else if (key == 123 || key == 0)
		move_left(t);
	return (0);
}

t_texture	manage_struct(t_texture t)
{
	t = ft_initialisation(t);
	t = position(t);
	t = c_count(t);
	return (t);
}

t_texture	open_window(t_texture t)
{
	t.move = 0;
	t = manage_struct(t);
	t.mlx = mlx_init();
	if (!t.mlx)
		exit(0);
	t = setup_window(t);
	t = ft_put_imgs_to_window(t.map, t);
	mlx_hook(t.window, 17, 0, ft_close, &t);
	mlx_hook(t.window, 2, (1L << 0), manage_event, &t);
	mlx_loop(t.mlx);
	return (t);
}
