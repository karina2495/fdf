/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:53:56 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:54:00 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	size_t				len2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	len2 = 0;
	if (!len)
		return (dst);
	if (!dst && !src)
		return (0);
	if (src2 < dst2)
		while (++len2 <= len)
			dst2[len - len2] = src2[len - len2];
	else
		while (len-- > 0)
			*(dst2++) = *(src2++);
	return (dst);
}
