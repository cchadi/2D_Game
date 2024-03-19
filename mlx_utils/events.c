#include "../so_long.h"

t_texture ft_exit(t_texture *t) 
{
     t->move +=1;
     ft_printf("see u ;) %d\n", t->move);
     mlx_destroy_window(t->mlx, t->window);
     exit(1);
     return (*t);
}

t_texture move_up(t_texture *t)
{
     if (t->map[t->y-1][t->x] == '0' || t->map[t->y -1][t->x] == 'C' || t->map[t->y -1][t->x] == 'P')
     {
          t->move +=1;
          ft_printf("Up %d\n", t->move);
          if (t->map[t->y-1][t->x] == 'C')
               t->counter -= 1;
          background_only(*t, t->space_path, t->x, t->y);
          img_to_win(*t, t->player_path, (t->x), (t->y -1));
          t->y -= 1;
     }
     else if (t->map[t->y-1][t->x] == 'E' && t->counter == 0)
          ft_exit(t);
     return (*t);
}

t_texture move_down(t_texture *t)
{
     if (t->map[t->y+1][t->x] == '0' || t->map[t->y +1][t->x] == 'C' || t->map[t->y +1][t->x] == 'P')
     {
          t->move +=1;
          ft_printf("Down %d\n", t->move);
          if (t->map[t->y+1][t->x] == 'C')
               t->counter -= 1;
          background_only(*t, t->space_path, t->x, t->y);
          img_to_win(*t, t->player_path, (t->x), (t->y +1));
          t->y += 1;
     }
     else if (t->map[t->y+1][t->x] == 'E' && t->counter == 0)
          ft_exit(t);
     return (*t);
}

t_texture move_right(t_texture *t)
{
     if (t->map[t->y][t->x+1] == '0' || t->map[t->y][t->x+1] == 'C' || t->map[t->y][t->x +1] == 'P')
     {
          t->move +=1;
          ft_printf("Right %d\n", t->move);
          if (t->map[t->y][t->x+1] == 'C')
               t->counter -= 1;
          background_only(*t, t->space_path, t->x, t->y);
          img_to_win(*t, t->player_path, (t->x +1), (t->y));
          t->x += 1;
     }
     else if (t->map[t->y][t->x+1] == 'E' && t->counter == 0)
          ft_exit(t);
     return (*t);
}

t_texture move_left(t_texture *t)
{
     if (t->map[t->y][t->x-1] == '0' || t->map[t->y][t->x -1] == 'C' || t->map[t->y][t->x -1] == 'P')
     {
          t->move +=1;
          ft_printf("Left %d\n", t->move);
          if (t->map[t->y][t->x -1] == 'C')
               t->counter -= 1;
          background_only(*t, t->space_path, t->x, t->y);
          img_to_win(*t, t->player_path, (t->x-1), (t->y));
          t->x -= 1;
     }
     else if (t->map[t->y][t->x-1] == 'E' && t->counter == 0)
          ft_exit(t);
     return (*t);
}