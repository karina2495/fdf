/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:04:49 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:04:52 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t	i;
	size_t	j;

	if (!*find)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == find[j]) && find[j])
			j++;
		if (!find[j])
			return ((char *)str + i);
		i++;
	}
	return (0);
}
