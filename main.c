#include "so_long.h"

char	*check_extention(char *arg)
{
	char *str;
	int i;

	if (ft_strchr(arg, '.') == NULL)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		if(arg[i] == '.')
			break;
		i++;
	}
	str = ft_substr(arg, i, ft_strlen(arg));
	return (str);
}

int main(int ac, char **av)
{
	t_texture t;
	char *ext;
	(void)ac;

	ext = check_extention(av[1]);
	if (!ext) 
		return (0);
	if (ft_strncmp(ext, ".ber", ft_strlen(".ber")) != 0)
	{
		ft_printf("use '.ber' as extention\n");
		return (0);
	}	
	int fd = open(av[1], O_RDONLY);
	t.map = valide_map(fd);
	if (t.map == NULL)
	{
		ft_printf("map non valide\n");
		return (0);
	}
	open_window(t);
}
