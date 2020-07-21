/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:10:13 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:10:14 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Управление вводом ключей с клавиатуры
*/

int				key_press(int keycode, void *param)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (keycode == MAIN_ESC)
		exit(0);
	if (keycode == NUM_PLUS || keycode == NUM_MINUS
		|| keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		zoom_fdf(keycode, fdf);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
			|| keycode == ARROW_LEFT || keycode == ARROW_RIGHT
			|| keycode == NUM_0 || keycode == MAIN_C
			|| keycode == NUM_5)
		color_fdf(keycode, fdf);
	else if (keycode == MAIN_LESS || keycode == MAIN_MORE
			|| keycode == NUM_2 || keycode == NUM_4
			|| keycode == NUM_6 || keycode == NUM_8)
		change_rot(keycode, fdf);
	else if (keycode == NUM_SLASH || keycode == NUM_STAR)
		change_pike(keycode, fdf);
	else if (keycode == MAIN_I || keycode == MAIN_P)
		change_proj(keycode, fdf);
	return (0);
}
