/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:18:12 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:18:14 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"
#include <stdio.h>

/*
** Вывод ошибки
*/

void			fdf_error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

/*
** Создание нового указателя
*/

t_point			point_new(int x, int y, t_fdf *fdf)
{
	t_point		new;

	new.x = x;
	new.y = y;
	new.z = fdf->coords[y * fdf->width + x];
	if (fdf->colors[y * fdf->width + x] == -1)
		new.color = ft_get_default_color(new.z, fdf);
	else
		new.color = fdf->colors[y * fdf->width + x];
	return (new);
}

/*
** Печать инструкции для пользования меню
*/

void			print_menu(t_fdf *fdf, int y)
{
	void		*mlx;
	void		*win;

	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 10, TEXT_COLOR, "User's menu");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Quite: ESC");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Pikes: * or /");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Color: 5/0");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "x - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "y - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "z - </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO - I");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel - P");
}
