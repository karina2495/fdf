/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_describe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:09:49 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:09:53 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Для macOS endian равно 0, что значит обратный порядок.
** Для цвета эти два формата выглядят так:
** Номер байта	 | 0 | 1 | 2 | 3
** Big Endian	 | 0 | R | B | G
** Little endian | В | G | R | 0
** В формате с прямым порядком байтов -> обратный порядок компонентов цвета:
*/

void			put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = x * 4 + y * fdf->size_line;
		fdf->data_addr[i] = color;
		fdf->data_addr[i + 1] = color >> 8;
		fdf->data_addr[i + 2] = color >> 16;
	}
}

/*
** draw_line: алгоритм рисования линий Брезенхема между точкой 1 и 2
** error вычисление отклонения от воображаемой линии между точками.
*/

void			des_line(t_point one, t_point two, t_fdf *fdf, int i)
{
	t_point		del;
	t_point		sign;
	t_point		cur;
	int			error;

	del.x = FT_ABS(two.x - one.x);
	del.y = FT_ABS(two.y - one.y);
	sign.x = one.x < two.x ? 1 : -1;
	sign.y = one.y < two.y ? 1 : -1;
	error = (del.x > del.y ? del.x : -del.y) / 2;
	cur = one;
	while (cur.x != two.x || cur.y != two.y)
	{
		put_pixel(fdf, cur.x, cur.y, f_color(cur, one, two, del));
		if (one.x == two.x && one.y == two.y)
			break ;
		i = error;
		if (i > -del.x && ((error -= del.y) || !error))
			cur.x += sign.x;
		if (i < del.y)
		{
			error += del.x;
			cur.y += sign.y;
		}
	}
}

/*
** data_addr: массив представляет область памяти, где хранится изображение.
** bits_per_pixel: количество бит, используемых для определения цветового
** оттенка пикселя. Истинный цвет иногда называют 24-битным цветом.
** Дополнительный байт (альфа-канал) используется для управления информацией.
** Берём координаты x и y, начиная с 0 и до границ высоты и ширины карты.
** отрисовка карты происходит начиная с левого нижнего угла на право.
*/

void			ft_describe(t_fdf *fdf)
{
	int			x;
	int			y;
	int			*image;
	int			i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = -1;
	while (++i < WIDTH * HEIGHT)
		image[i] = BACKGROUND;
	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			if (x != fdf->width - 1)
				des_line(project(x, y, fdf), project(x + 1, y, fdf), fdf, 0);
			if (y != fdf->height - 1)
				des_line(project(x, y, fdf), project(x, y + 1, fdf), fdf, 0);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	(fdf->con_mou->menu) ? (print_menu(fdf, 0)) : (fdf->con_mou->menu = 0);
}
