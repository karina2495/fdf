/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:17:26 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:17:29 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Перекладываем координаты точек в массив coords, а цвета в массив colors.
** Заносим в структуру данные о самой высокой и самой низкой точке на карте,
** это необходимо для перехода одного цвета в другой.
*/

void			stack_arrays(t_coord **coords_stack, t_fdf *fdf)
{
	t_coord		*coord;

	fdf->size = fdf->width * fdf->height - 1;
	if ((!(fdf->coords = (int *)ft_memalloc(sizeof(int) * fdf->size + 1)))
		|| (!(fdf->colors = (int *)ft_memalloc(sizeof(int) * fdf->size + 1))))
		fdf_error(ERR_MEM_ALLOC);
	while ((coord = get_last_coords(coords_stack)))
	{
		fdf->coords[fdf->size] = coord->z;
		fdf->colors[fdf->size] = coord->color;
		if (coord->z > fdf->z_max)
			fdf->z_max = coord->z;
		if (coord->z < fdf->z_min)
			fdf->z_min = coord->z;
		fdf->size--;
		free(coord);
	}
}
