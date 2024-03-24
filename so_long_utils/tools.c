/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:17:50 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 07:40:27 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_alloc_void(char *str)
{
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	len;
	char	*s;

	s = NULL;
	if (!s1 || !set)
		return (0);
	if (!s1[0])
		return (ft_alloc_void(s));
	len = ft_strlen(s1);
	i = 0;
	len--;
	while (len && ft_strchr(set, s1[len]))
		len--;
	while (s1[i + 1] != '\0' && ft_strchr(set, s1[i]))
		i++;
	if (len < i)
		return (ft_alloc_void(s));
	return (ft_substr(s1, i, len - i + 1));
}
