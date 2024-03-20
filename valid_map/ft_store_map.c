#include "../so_long.h"

char **ft_store_map(int fd)
{
     char **map_origin;
     char *line;
     char *buffer = NULL;
     line = ft_strdup(get_next_line(fd));
	if (line == NULL)
		return (0);
	buffer = ft_strjoin(buffer, line);
     while (line != NULL)
	{
		line = ft_strdup(get_next_line(fd));
		if (line == NULL)
			break ;
		buffer = ft_strjoin(buffer, line);
	}
     map_origin = ft_split(buffer, '\n');
     return (map_origin);
}

char **make_copy(char **ptr)
{
	int l;
	char **map;

	l = 0;
	while (ptr[l])
	{
		l++;
	}
	map = malloc((l + 1) * sizeof(char *));
	map[l] = NULL;
	l = 0;
	while(ptr[l])
	{
		map[l] = ft_strdup(ptr[l]);
		l++;
	}
	return (map);
}
