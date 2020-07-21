/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:10:41 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:10:42 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Массивы (int) coord/colors для хранения координат z и цвета точек.
** Максимальный и минимальный размер для высоты/глубины при отрисовке z.
*/

t_fdf				*init(void)
{
	t_fdf			*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		fdf_error(ERR_MEM_ALLOC);
	fdf->width = 0;
	fdf->height = 0;
	fdf->coords = NULL;
	fdf->colors = NULL;
	fdf->z_min = FT_INT_MAX;
	fdf->z_max = FT_INT_MIN;
	return (fdf);
}

/*
** zoom: масштабирование реального размера точек до размера окна при отрисовке.
** z_altitude: изменение реального размера высоты/глубины до заданной.
** projection: флаг на 1, значит проекция будет изометрической
** x_move / y_move: текущее положение цетра карты.
*/

t_con_mou			*control_init(t_fdf *fdf)
{
	t_con_mou		*control;

	if (!(control = (t_con_mou *)ft_memalloc(sizeof(t_con_mou))))
		fdf_error(ERR_CONTROL);
	control->zoom = FT_MIN(WIDTH / fdf->width / 2, HEIGHT / fdf->height / 2);
	control->alf = 0;
	control->bet = 0;
	control->gam = 0;
	control->projection = 1;
	control->z_altitude = 4;
	control->x_move = 0;
	control->y_move = -150;
	control->color = 0;
	control->menu = 1;
	return (control);
}
