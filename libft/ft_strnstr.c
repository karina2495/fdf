/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:03:59 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:04:02 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*find)
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] == find[j] && find[j])
			j++;
		if (!find[j])
			return ((char *)str + i);
		i++;
	}
	return (0);
}
