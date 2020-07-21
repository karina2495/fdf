/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:17:55 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:17:57 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** mouse_pressed_hook - для события нажатия мыши, которое передается
** mlx_hook(). mlx_hook() передаст "int button, int x, int y", а затем
** любые параметры также передаются в mlx_hook () функции, когда мышь нажата.
** Чтобы обработать кнопку мыши используется функция mouse_press
*/

int				mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom_fdf(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->con_mou->is_pressed = 1;
	return (0);
}

/*
** Для обработки нажатия кнопки мыши используется функция mouse_release
*/

int				mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->con_mou->is_pressed = 0;
	return (0);
}

/*
** Чтобы справиться с движением мыши используется функция mouse_move
*/

int				mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->con_mou->previous_x = fdf->con_mou->x;
	fdf->con_mou->previous_y = fdf->con_mou->y;
	fdf->con_mou->x = x;
	fdf->con_mou->y = y;
	if (fdf->con_mou->is_pressed)
	{
		fdf->con_mou->bet += (x - fdf->con_mou->previous_x) * 0.002;
		fdf->con_mou->alf += (y - fdf->con_mou->previous_y) * 0.002;
		ft_describe(fdf);
	}
	return (0);
}
