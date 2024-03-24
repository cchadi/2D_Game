/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:30 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 14:25:28 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_p(char *ptr)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'P')
			p += 1;
		i++;
	}
	return (p);
}

int	check_d(char *ptr)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'E')
			e += 1;
		i++;
	}
	return (e);
}

int	check_c(char *ptr)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 'C')
			c += 1;
		i++;
	}
	return (c);
}

int	check_o(char *ptr)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	if (ptr[i] == '\0')
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] != 'C' && ptr[i] != 'P' && ptr[i] != 'E' && ptr[i] != '1'
			&& ptr[i] != '0')
			o += 1;
		i++;
	}
	return (o);
}

int	check_pec(char **ptr)
{
	int			l;
	t_check_in	s;

	s.other = 0;
	s.player = 0;
	s.exit = 0;
	s.collecteble = 0;
	l = 0;
	while (ptr[l])
	{
		s.other += check_o(ptr[l]);
		s.player += check_p(ptr[l]);
		s.exit += check_d(ptr[l]);
		s.collecteble += check_c(ptr[l]);
		l++;
	}
	if (s.player > 1 || s.player == 0 || s.exit > 1 || s.exit == 0
		|| s.collecteble == 0 || s.other > 0)
		return (0);
	return (1);
}
