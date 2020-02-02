/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:01:31 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:01:34 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dst[i] && i < n)
		i++;
	while ((src[j]) && ((i + j + 1) < n))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != n)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
