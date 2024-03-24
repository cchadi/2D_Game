/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:03:58 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/20 22:03:59 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putstr(char *s, int len)
{
	int	i;

	if (!s)
		return (len = ft_putstr("(null)", len));
	i = 0;
	while (s[i])
	{
		len = ft_putchar(s[i], len);
		i++;
	}
	return (len);
}
