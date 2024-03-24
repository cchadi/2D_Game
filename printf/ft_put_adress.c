/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:03:42 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/20 22:03:43 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_adress(unsigned long decimal, int len)
{
	if (!decimal)
		return (len = ft_putstr("0x0", len));
	len = ft_putstr("0x", len);
	len = ft_decimal_to_hex(decimal, len);
	return (len);
}
