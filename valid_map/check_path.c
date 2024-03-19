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

// char  **ft_flood_fill(char **ptr, int y, int x)
// {
//      if (ptr[y][x] == '1')
//           return (ptr);
//      ptr[y][x] = 'X';
//      ft_flood_fill(ptr, y+1, x);
//      ft_flood_fill(ptr, y-1, x);
//      ft_flood_fill(ptr, y, x+1);
//      ft_flood_fill(ptr, y, x-1);
//      return (ptr);
// }