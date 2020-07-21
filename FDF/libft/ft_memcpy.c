/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:53:26 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:53:30 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned char		*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (!len)
		return (dst);
	while (len-- > 0)
		*(dst2++) = *(src2++);
	return (dst);
}
