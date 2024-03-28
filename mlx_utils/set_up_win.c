/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:03:03 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/28 17:55:03 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	windows_size(char **map, t_texture t)
{
	int	i;
	int	l;

	l = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i])
		{
			i++;
		}
		l++;
	}
	t.height = l;
	t.width = i;
	return (t);
}

t_texture	setup_window(t_texture t)
{
	t = windows_size(t.map, t);
	if (t.width <= 100 && t.height <= 51)
	{
		t.window = mlx_new_window(t.mlx, (t.width * 32),
				(t.height * 32), "Game");
		if (!t.window)
			exit(0);
		return (t);
	}
	ft_printf("Error\nMap Too Big !! \n");
	exit(0);
}
