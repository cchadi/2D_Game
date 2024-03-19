#include "../so_long.h"

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len += 1;
	return (len);
}
