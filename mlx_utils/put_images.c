#include "../so_long.h"

t_texture      background_only(t_texture t, char *path, int i, int l)
{
     int  width;
     int  height;

     t.img = mlx_xpm_file_to_image(t.mlx, path, &width, &height);
     mlx_put_image_to_window(t.mlx, t.window, t.img, (i*32), (l*32));
     return (t);
}

t_texture      img_to_win(t_texture t, char *path, int i, int l)
{
     int  width;
     int  height;

     t.img = mlx_xpm_file_to_image(t.mlx, path, &width, &height);
     mlx_put_image_to_window(t.mlx, t.window, t.img, (i*32), (l*32));
     return (t);
}

t_texture      img_with_background(t_texture t, char *path, int i, int l)
{
     int  width;
     int  height;
     char *background;

     background = "./mlx_utils/image.xpm/background.xpm";
     t.img = mlx_xpm_file_to_image(t.mlx, background, &width, &height);
     mlx_put_image_to_window(t.mlx, t.window, t.img, (i*32), (l*32));
     t.img = mlx_xpm_file_to_image(t.mlx, path, &width, &height);
     mlx_put_image_to_window(t.mlx, t.window, t.img, (i*32), (l*32));
     return (t);
}



t_texture      ft_put_imgs_to_window(char **ptr, t_texture t)
{
     int l;
     int i;

     l = 0;
     while (ptr[l])
     {
          i = 0;
          while (ptr[l][i])
          {
               if (ptr[l][i] == '0')
                   img_to_win(t, t.space_path, i, l);
               else if (ptr[l][i] =='1')
                    img_to_win(t, t.wall_path, i, l);
               else if (ptr[l][i] =='C')
                    img_with_background(t, t.collect_path, i, l);
               else if (ptr[l][i] =='P')
                    img_with_background(t, t.player_path, i, l);
               else if (ptr[l][i] =='E')
                    img_with_background(t, t.door_path, i, l);
               i++;
          }
          l++;
     }
     return (t);
}
