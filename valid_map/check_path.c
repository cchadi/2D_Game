#include "../so_long.h"

t_texture      position(t_texture t)
{
     t.y = 0;
     while(t.map[t.y])
     {
          t.x = 0;
          while(t.map[t.y][t.x])
          {
               if (t.map[t.y][t.x] == 'P')
                    return (t);
               t.x++;
          }
          t.y++;
     }
     return (t);
}

t_texture      c_count(t_texture t)
{
     int l;
     int i;
     t.counter = 0;

     l = 0;
     while(t.map[l])
     {
          i = 0;
          while(t.map[l][i])
          {
               if (t.map[l][i] == 'C')
                    t.counter += 1;
               i++;
          }
          l++;
     }
     return (t);
}

void     ft_flood_fill(char **ptr, int y, int x)
{
     if (ptr[y][x] == '1' || ptr[y][x] == 'E' || ptr[y][x] == 'X')
          return;
     ptr[y][x] = 'X';
     ft_flood_fill(ptr, y+1, x);
     ft_flood_fill(ptr, y-1, x);
     ft_flood_fill(ptr, y, x+1);
     ft_flood_fill(ptr, y, x-1);
     return;
}

void     ft_flood_exit(char **ptr, int y, int x)
{
     if (ptr[y][x] == '1' || ptr[y][x] == 'X')
          return;
     ptr[y][x] = 'X';
     ft_flood_exit(ptr, y+1, x);
     ft_flood_exit(ptr, y-1, x);
     ft_flood_exit(ptr, y, x+1);
     ft_flood_exit(ptr, y, x-1);
     return;
}

int  path(char **ptr, char c)
{
     int l;

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
     (void)s;
     char **ptr;

     ptr = make_copy(map);
     ft_flood_fill(ptr, s.y, s.x);
     if (path(ptr, 'C') == 0)
          return (0);
     free(ptr);
     ptr = make_copy(map);
     ft_flood_exit(ptr, s.y, s.x);
     int l = 0;
     while (ptr[l])
     {
          printf("%s\n", ptr[l]);
          l++;
     }
     if (path(ptr, 'E') == 0)
          return (0); 
     return (1);
}