/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:37 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 14:26:05 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_store_map(int fd)
{
	char	**map_origin;
	char	*line;
	char	*buffer;

	buffer = NULL;
	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	buffer = ft_strjoin(buffer, line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	map_origin = ft_split(buffer, '\n');
	free(buffer);
	return (map_origin);
}

char	**make_copy(char **ptr)
{
	int		l;
	char	**map;

	l = 0;
	while (ptr[l])
	{
		l++;
	}
	map = malloc((l + 1) * sizeof(char *));
	if (!map)
	{
		free(map);
		return (NULL);
	}
	map[l] = NULL;
	l = 0;
	while (ptr[l])
	{
		map[l] = ft_strdup(ptr[l]);
		l++;
	}
	return (map);
}
