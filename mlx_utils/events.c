/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:02:34 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 14:15:07 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	ft_exit(t_texture *t)
{
	t->move += 1;
	ft_printf("See u ;) %d\n", t->move);
	mlx_destroy_window(t->mlx, t->window);
	exit(0);
	return (*t);
}

t_texture	move_up(t_texture *t)
{
	if (t->map[t->y - 1][t->x] == '0' || t->map[t->y - 1][t->x] == 'C'
		|| t->map[t->y - 1][t->x] == 'P' || t->map[t->y - 1][t->x] == 'c')
	{
		t->move += 1;
		ft_printf("Move Up %d\n", t->move);
		if (t->map[t->y - 1][t->x] == 'C')
		{
			t->map[t->y - 1][t->x] = 'c';
			t->counter -= 1;
		}
		background_only(*t, t->space_path, t->x, t->y);
		img_to_win(*t, t->player_path, (t->x), (t->y - 1));
		t->y -= 1;
	}
	else if (t->map[t->y - 1][t->x] == 'E' && !(t->counter > 0))
		ft_exit(t);
	return (*t);
}

t_texture	move_down(t_texture *t)
{
	if (t->map[t->y + 1][t->x] == '0' || t->map[t->y + 1][t->x] == 'C'
		|| t->map[t->y + 1][t->x] == 'P' || t->map[t->y + 1][t->x] == 'c')
	{
		t->move += 1;
		ft_printf("Move Down %d\n", t->move);
		if (t->map[t->y + 1][t->x] == 'C')
		{
			t->map[t->y + 1][t->x] = 'c';
			t->counter -= 1;
		}
		background_only(*t, t->space_path, t->x, t->y);
		img_to_win(*t, t->player_path, (t->x), (t->y + 1));
		t->y += 1;
	}
	else if (t->map[t->y + 1][t->x] == 'E' && !(t->counter > 0))
		ft_exit(t);
	return (*t);
}

t_texture	move_right(t_texture *t)
{
	if (t->map[t->y][t->x + 1] == '0' || t->map[t->y][t->x + 1] == 'C'
		|| t->map[t->y][t->x + 1] == 'P' || t->map[t->y][t->x + 1] == 'c')
	{
		t->move += 1;
		ft_printf("Move Right %d\n", t->move);
		if (t->map[t->y][t->x + 1] == 'C')
		{
			t->map[t->y][t->x + 1] = 'c';
			t->counter -= 1;
		}
		background_only(*t, t->space_path, t->x, t->y);
		img_to_win(*t, t->player_path, (t->x + 1), (t->y));
		t->x += 1;
	}
	else if (t->map[t->y][t->x + 1] == 'E' && !(t->counter > 0))
		ft_exit(t);
	return (*t);
}

t_texture	move_left(t_texture *t)
{
	if (t->map[t->y][t->x - 1] == '0' || t->map[t->y][t->x - 1] == 'C'
		|| t->map[t->y][t->x - 1] == 'P' || t->map[t->y][t->x - 1] == 'c')
	{
		t->move += 1;
		ft_printf("Move Left %d\n", t->move);
		if (t->map[t->y][t->x - 1] == 'C')
		{
			t->map[t->y][t->x - 1] = 'c';
			t->counter -= 1;
		}
		background_only(*t, t->space_path, t->x, t->y);
		img_to_win(*t, t->player_path, (t->x - 1), (t->y));
		t->x -= 1;
	}
	else if (t->map[t->y][t->x - 1] == 'E' && !(t->counter > 0))
		ft_exit(t);
	return (*t);
}
