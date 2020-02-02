/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:48:43 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:48:48 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i] = '\0';
	while (n)
	{
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
