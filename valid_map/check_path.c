/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:27 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/22 19:31:29 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	position(t_texture t)
{
	t.y = 0;
	while (t.map[t.y])
	{
		t.x = 0;
		while (t.map[t.y][t.x])
		{
			if (t.map[t.y][t.x] == 'P')
				return (t);
			t.x++;
		}
		t.y++;
	}
	return (t);
}

t_texture	c_count(t_texture t)
{
	int	l;
	int	i;

	t.counter = 0;
	l = 0;
	while (t.map[l])
	{
		i = 0;
		while (t.map[l][i])
		{
			if (t.map[l][i] == 'C')
				t.counter += 1;
			i++;
		}
		l++;
	}
	return (t);
}

int	path(char **ptr, char c)
{
	int	l;

	l = 0;
	while (ptr[l])
	{
		if (ft_strchr(ptr[l], c) != NULL)
			return (0);
		l++;
	}
	return (1);
}

int	check_path(char **map, t_texture s)
{
	char	**ptr;

	ptr = make_copy(map);
	ft_flood_fill(ptr, s.y, s.x);
	if (path(ptr, 'C') == 0)
	{
		free(ptr);
		return (0);
	}
	free(ptr);
	ptr = make_copy(map);
	ft_flood_exit(ptr, s.y, s.x);
	if (path(ptr, 'E') == 0)
	{
		free(ptr);
		return (0);
	}
	free(ptr);
	return (1);
}
