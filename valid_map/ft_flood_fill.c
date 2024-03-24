/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:11:03 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 08:19:13 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flood_fill(char **ptr, int y, int x)
{
	if (ptr[y][x] == '1' || ptr[y][x] == 'E' || ptr[y][x] == 'X')
		return ;
	ptr[y][x] = 'X';
	ft_flood_fill(ptr, y + 1, x);
	ft_flood_fill(ptr, y - 1, x);
	ft_flood_fill(ptr, y, x + 1);
	ft_flood_fill(ptr, y, x - 1);
	return ;
}

void	ft_flood_exit(char **ptr, int y, int x)
{
	if (ptr[y][x] == '1' || ptr[y][x] == 'F')
		return ;
	ptr[y][x] = 'F';
	ft_flood_exit(ptr, y + 1, x);
	ft_flood_exit(ptr, y - 1, x);
	ft_flood_exit(ptr, y, x + 1);
	ft_flood_exit(ptr, y, x - 1);
	return ;
}
