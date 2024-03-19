#include "../so_long.h"

t_texture      search(char **map, char c)
{
	t_texture t;
     t.y = 0;
     while(map[t.y])
     {
          t.x = 0;
          while(map[t.y][t.x])
          {
               if (map[t.y][t.x] == c)
                    return (t);
               t.x++;
          }
          t.y++;
     }
     return (t);
}

char **valide_map(int fd)
{
	t_texture s;
	char **ptr;
	int result;
	
	ptr = ft_store_map(fd);
	if (!ptr)
		return (NULL);
	result = contour(ptr);
	if (result == 0)
		return (NULL);
	result = check_PEC(ptr);
	if (result == 0)
		return (NULL);
	s = search(ptr, 'P');
	result = check_path(ptr, s);
	if (result == 0)
		return (NULL);
	return (ptr);
}
