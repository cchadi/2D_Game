#include "../so_long.h"

int check_lenght(char **ptr)
{
     int l;
     size_t lenght;

     l = 0;
     lenght = ft_strlen(ptr[l]);
     while(ptr[l] != NULL)
     {
          if (ft_strlen(ptr[l]) != lenght)
               return (0);
          l++;
     }
     return (1);
}

int check_side_lines(char *ptr)
{
     int i = 0;
     while (ptr[i])
	{
		if (ptr[i] != '1')
			return (0);
		i++;	
	}
     return (1);
}

int check_between_lines(char *ptr)
{
     size_t len;
     
     if (ptr == NULL)
          return (0);
     len = ft_strlen(ptr);
	if (ptr[0] != '1' || ptr[len -1] != '1')
		return (0);
	return (1);
}

int contour(char **ptr)
{
	int l;
	int side;
	int between;
	int lenght;

	l = 0;
	lenght = check_lenght(ptr);
	if (lenght == 0)
		return (0);
	side = check_side_lines(ptr[l]);
	if (side == 0)
		return (0);
	l++;
	while (ptr[l] != NULL)
	{
		between = check_between_lines(ptr[l]);
		if (between == 0)
			return (0);
		l++;
	}
	side = check_side_lines(ptr[l -1]);
	if (side == 0)
		return (0);
	return (1);
}

