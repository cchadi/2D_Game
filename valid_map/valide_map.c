#include "../so_long.h"

char **valide_map(int fd)
{
	char **ptr;
	int result;
	
	ptr = ft_store_map(fd);
	result = contour(ptr);
	if (result == 0)
		return (NULL);
	result = check_PEC(ptr);
	if (result == 0)
		return (NULL);
	return (ptr);
}
