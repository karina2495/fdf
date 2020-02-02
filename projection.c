/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:10:28 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:10:30 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Поворот карты по осям xyz
*/

void			rotate_xyz(int *x, int *y, int *z, t_fdf *fdf)
{
	int			prev_y;
	int			prev_x;

	prev_x = *x;
	prev_y = *y;
	if (fdf->con_mou->alf)
	{
		*y = prev_y * cos(fdf->con_mou->alf) + *z * sin(fdf->con_mou->alf);
		*z = -prev_y * sin(fdf->con_mou->alf) + *z * cos(fdf->con_mou->alf);
	}
	if (fdf->con_mou->bet)
	{
		*x = prev_x * cos(fdf->con_mou->bet) + *z * sin(fdf->con_mou->bet);
		*z = -prev_x * sin(fdf->con_mou->bet) + *z * cos(fdf->con_mou->bet);
	}
	if (fdf->con_mou->gam)
	{
		*x = prev_x * cos(fdf->con_mou->gam) - prev_y * sin(fdf->con_mou->gam);
		*y = prev_x * sin(fdf->con_mou->gam) + prev_y * cos(fdf->con_mou->gam);
	}
}

/*
** Истинная изометрическая проекция использует угол 30° (0,523599 рад).
** Изометрическая проекция 2:1 использует угол 26,57° (0,46373398 рад).
*/

void			ft_iso(int *x, int *y, int z)
{
	int			prev_x;
	int			prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(RADIAN);
	*y = -z + (prev_x + prev_y) * sin(RADIAN);
}

/*
** производим манипуляции с текущими координатами:
** control_mouse->zoom: увеличение реального
** размера фигуры, p.z размер высот/низин
** control_mouse->zoom / 2: поворот фигуры относительно её середины
** rotate_xyz: верчение под любым углом, по соответсутвующим осям xyz
** move: перемещение карты с помощью стрелок
*/

t_point			project(int x, int y, t_fdf *fdf)
{
	t_point		poin;

	poin = point_new(x, y, fdf);
	poin.x *= fdf->con_mou->zoom;
	poin.y *= fdf->con_mou->zoom;
	poin.z *= fdf->con_mou->zoom / fdf->con_mou->z_altitude;
	poin.x -= (fdf->width * fdf->con_mou->zoom) / 2;
	poin.y -= (fdf->height * fdf->con_mou->zoom) / 2;
	rotate_xyz(&poin.x, &poin.y, &poin.z, fdf);
	if (fdf->con_mou->projection)
		ft_iso(&poin.x, &poin.y, poin.z);
	poin.x += WIDTH / 2 + fdf->con_mou->x_move;
	poin.y += (HEIGHT + fdf->height * fdf->con_mou->zoom) / 2
				+ fdf->con_mou->y_move;
	return (poin);
}
