#include "../so_long.h"

t_texture      windows_size(char **map, t_texture t)
{
     int i;
     int l;

     l = 0;
     while(map[l])
     {
          i = 0;
          while(map[l][i])
          {
               i++;
          }
          l++;
     }
     t.height = l;
     t.width = i;
     return (t);
}

t_texture      setup_window(t_texture t)
{
	t = windows_size(t.map, t);
	t.window = mlx_new_window(t.mlx, (t.width * 32), (t.height * 32), "Game");
	if (!t.window)
        exit (0);
     return (t);
}

