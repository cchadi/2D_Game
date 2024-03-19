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
     if (ptr[y][x] == '1' || ptr[y][x] == 'E')
          return;
     if (ptr[y][x] != 'P')
          ptr[y][x] = 'X';
     ft_flood_fill(ptr, y+1, x);
     ft_flood_fill(ptr, y-1, x);
     ft_flood_fill(ptr, y, x+1);
     ft_flood_fill(ptr, y, x-1);
     return;
}

void     ft_flood_exit(char **ptr, int y, int x)
{
     if (ptr[y][x] == '1')
          return;
     // if (ptr[y][x] != '0' && ptr[y][x] != 'P')
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

int	check_path(char **ptr, t_texture s)
{
     int l;
     // int i;
     (void)s;
   
     ft_flood_fill(ptr, s.y, s.x);
     l = 0;
     while(ptr[l++])
     {
          printf("%s\n", ptr[l]);
          l++;
     }
     if (path(ptr, 'C') == 0)
          return (0);
     s = search(ptr, 'P');
     ft_flood_exit(ptr, s.y, s.x);
     if (path(ptr, 'E') == 0)
          return (0);
     

     // l = 0;
     // while(ptr[l])
     // {
     //      i = 0;
     //      while (ptr[l][i])
     //      {
     //           if (ptr[l][i] == 'X' && (l != s.y && i != s.x))
     //                ptr[l][i] = 'C';
     //           i++;         
     //      }
     //      l++;
     // }
     // ptr[s.y][s.x] = 'E';
     return (1);
}