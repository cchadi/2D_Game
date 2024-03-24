CC = cc

CFLAGS = -Wall -Wextra -Werror 

NAME = so_long

SRCS = valid_map/check_pec.c valid_map/contour.c valid_map/ft_flood_fill.c \
	valid_map/ft_store_map.c valid_map/valide_map.c so_long_utils/tools.c \
 	so_long_utils/libft_utils.c  so_long_utils/get_next_line.c so_long_utils/get_next_line_utils.c \
	main.c valid_map/check_path.c mlx_utils/put_images.c mlx_utils/set_up_win.c \
	mlx_utils/open_window.c mlx_utils/events.c printf/ft_printf.c printf/ft_decimal_to_hex.c \
	printf/ft_check.c printf/ft_decimal_to_hexa.c printf/ft_put_positive.c printf/ft_putchar.c 	\
	printf/ft_putnbr.c printf/ft_putstr.c printf/ft_put_adress.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
