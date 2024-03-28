/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:27:17 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/28 18:09:09 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_check_in
{
	int		player;
	int		exit;
	int		collecteble;
	int		other;
}			t_check_in;

typedef struct s_texture
{
	int		y;
	int		x;
	int		move;
	int		counter;
	int		width;
	int		height;
	char	*ext;
	void	*mlx;
	void	*window;
	void	*img;
	char	*wall_path;
	char	*door_path;
	char	*space_path;
	char	*player_path;
	char	*collect_path;
	char	**map;
}			t_texture;

int			ft_check(char s, va_list args, int len);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c, int len);
int			ft_putstr(char *s, int len);
int			ft_putnbr(int c, int len);
int			ft_put_positive(unsigned int c, int len);
int			ft_decimal_to_hex(unsigned long decimal, int len);
int			ft_decimal_to_hexa(unsigned int decimal, int len);
int			ft_put_adress(unsigned long decimal, int len);
char		*get_next_line(int fd);
char		*ft_readfile(int fd, char *buffer);
char		*returnline(char *buffer);
size_t		ft_strlen(const char *s);
char		*ft_strdup(char *s1);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		**ft_split(char *s, char c);
char		*ft_strtrim(char *s1, char *set);
char		**ft_store_map(int fd);
char		**make_copy(char **ptr);
int			contour(char **ptr);
int			check_pec(char **ptr);
int			check_path(char **map, t_texture s);
char		**valide_map(int fd);
void		ft_flood_fill(char **ptr, int y, int x);
void		ft_flood_exit(char **ptr, int y, int x);
t_texture	position(t_texture t);
t_texture	setup_window(t_texture t);
t_texture	ft_put_imgs_to_window(char **ptr, t_texture t);
t_texture	background_only(t_texture t, char *path, int i, int l);
t_texture	img_to_win(t_texture t, char *path, int i, int l);
t_texture	open_window(t_texture t);
t_texture	ft_exit(t_texture *t);
t_texture	move_up(t_texture *t);
t_texture	move_down(t_texture *t);
t_texture	move_right(t_texture *t);
t_texture	move_left(t_texture *t);
t_texture	c_count(t_texture t);
t_texture	search(char **map, char c);

#endif
