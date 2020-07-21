/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:18:04 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:18:06 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Достаём первую (верхнюю) координату стэка.
*/

t_coord			*get_last_coords(t_coord **c_stack)
{
	t_coord		*vertex;

	vertex = NULL;
	if (c_stack && *c_stack)
	{
		vertex = *c_stack;
		*c_stack = (*c_stack)->next;
	}
	return (vertex);
}
