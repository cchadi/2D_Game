#include "../so_long.h"

int	check_P(char *ptr)
{
	int i;
	int P;

	i = 0;
	P = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'P')
			P += 1;
		i++;
	}
	return (P);
}

int	check_E(char *ptr)
{
	int i;
	int E;

	E = 0;
	i = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'E')
			E += 1;
		i++;
	}
	return (E);
}

int	check_C(char *ptr)
{
	int i;
	int C;

	i = 0;
	C = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'C')
			C += 1;
		i++;
	}
	return (C);
}

int	check_O(char *ptr)
{
	int i;
	int O;

	i = 0;
	O = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] != 'C' && ptr[i] != 'P' && ptr[i] != 'E' && ptr[i] != '1' && ptr[i] != '0')
			O += 1;
		i++;
	}
	return (O);
}

int check_PEC(char **ptr)
{
	int l;
	t_check_in s;

	s.other = 0;
	s.player = 0;
	s.exit = 0;
	s.collecteble = 0;
	l = 0;
	while (ptr[l])
	{
		s.other += check_O(ptr[l]);
		s.player += check_P(ptr[l]);
		s.exit += check_E(ptr[l]);
		s.collecteble += check_C(ptr[l]);
		l++;
	}
	if (s.player > 1 || s.player == 0 || s.exit > 1 || s.exit == 0 || s.collecteble == 0 || s.other > 0)
		return (0);
	return (1);
}

// int main()
// {
// 	int fd = open("map.ber", O_RDONLY);
// 	char **map = ft_store_map(fd);
// 	int f = check_PEC(map);
// 	printf("%d\n", f);
	
// }
