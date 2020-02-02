/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:54:30 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:54:35 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int		len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
