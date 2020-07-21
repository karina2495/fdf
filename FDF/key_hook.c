/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:10:04 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:10:06 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Приближение или отдаление фигуры с помощью клавиатуры +(-) или колёсика мыши
*/

void			zoom_fdf(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PLUS || keycode == MOUSE_SCROLL_UP)
		fdf->con_mou->zoom++;
	else if (keycode == NUM_MINUS || keycode == MOUSE_SCROLL_DOWN)
		fdf->con_mou->zoom--;
	if (fdf->con_mou->zoom < 1)
		fdf->con_mou->zoom = 1;
	ft_describe(fdf);
}

/*
** Перемещение по карте с помощью стрелок на клавиатуре. Смена цвета.
*/

void			color_fdf(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_C)
		fdf->con_mou->menu ? (fdf->con_mou->menu = 0)
		: (fdf->con_mou->menu = 1);
	else if (keycode == NUM_0)
		fdf->con_mou->color = 0;
	else if (keycode == NUM_5)
		fdf->con_mou->color = 1;
	else if (keycode == ARROW_RIGHT)
		fdf->con_mou->x_move += 10;
	else if (keycode == ARROW_LEFT)
		fdf->con_mou->x_move -= 10;
	else if (keycode == ARROW_DOWN)
		fdf->con_mou->y_move += 10;
	else if (keycode == ARROW_UP)
		fdf->con_mou->y_move -= 10;
	ft_describe(fdf);
}

/*
** Поворот фигуры
*/

void			change_rot(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_LESS)
		fdf->con_mou->gam -= 0.1;
	else if (keycode == MAIN_MORE)
		fdf->con_mou->gam += 0.1;
	else if (keycode == NUM_2)
		fdf->con_mou->alf -= 0.1;
	else if (keycode == NUM_4)
		fdf->con_mou->bet -= 0.1;
	else if (keycode == NUM_6)
		fdf->con_mou->bet += 0.1;
	else if (keycode == NUM_8)
		fdf->con_mou->alf += 0.1;
	ft_describe(fdf);
}

/*
** Изменение параметра z. Управление вершинами(глубиной) карты
*/

void			change_pike(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_SLASH)
		fdf->con_mou->z_altitude -= 0.3;
	else if (keycode == NUM_STAR)
		fdf->con_mou->z_altitude += 0.3;
	if (fdf->con_mou->z_altitude < 0.3)
		fdf->con_mou->z_altitude = 0.3;
	else if (fdf->con_mou->z_altitude > 10)
		fdf->con_mou->z_altitude = 10;
	ft_describe(fdf);
}

/*
** Изменение типа проекции: I - изометрический, P - параллельный
*/

void			change_proj(int keycode, t_fdf *fdf)
{
	fdf->con_mou->alf = 0;
	fdf->con_mou->bet = 0;
	fdf->con_mou->gam = 0;
	if (keycode == MAIN_I)
		fdf->con_mou->projection = 1;
	else if (keycode == MAIN_P)
		fdf->con_mou->projection = 0;
	ft_describe(fdf);
}
