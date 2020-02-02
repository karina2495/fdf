/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:05:23 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:05:27 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	beg;
	size_t	end;

	if (!s)
		return (0);
	beg = 0;
	end = 0;
	while (s[beg] && (s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n'))
		beg++;
	if (beg == ft_strlen(s))
		return (ft_strnew(beg));
	end = ft_strlen(s) - 1;
	while (s[end] && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (!(res = ft_strnew(end - beg + 1)))
		return (0);
	ft_strncpy(res, (s + beg), (end - beg + 1));
	return (res);
}
