/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:41 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 14:27:04 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_texture	search(char **map, char c)
{
	t_texture	t;

	t.y = 0;
	while (map[t.y])
	{
		t.x = 0;
		while (map[t.y][t.x])
		{
			if (map[t.y][t.x] == c)
				return (t);
			t.x++;
		}
		t.y++;
	}
	return (t);
}

void	*ft_free(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
	{
		free(ptr[l]);
		l++;
	}
	free(ptr);
	return (0);
}

char	**valide_map(int fd)
{
	t_texture	s;
	char		**ptr;
	int			result;

	ptr = ft_store_map(fd);
	if (!ptr)
		return (NULL);
	result = contour(ptr);
	if (result == 0)
		return (ft_free(ptr));
	result = check_pec(ptr);
	if (result == 0)
		return (ft_free(ptr));
	s = search(ptr, 'P');
	result = check_path(ptr, s);
	if (result == 0)
		return (ft_free(ptr));
	return (ptr);
}
