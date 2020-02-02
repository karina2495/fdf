/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inkey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:17:34 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:17:36 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
**mlx_init: даёт соединение между программным обеспечением и дисплеем
** mlx_new_window: создает новое окно на экране, используя параметры size_x
** и size_y, fdf->mlx - это идентификатор соединения
** mlx_new_image: позволяет манипулировать изображениями
** mlx_get_data_addr: возвращает информацию о созданном изображении.
** bits_per_pixel заполнется количеством битов для представления цвета пикселя
** size_line: кол-во байтов для хранения одной строки изображения в памяти
** endian: нужно сохранять цвет пикселя в изображении с прямым порядком байтов
** (endian == 0) или с прямым порядком байтов (endian == 1).
*/

t_fdf			*ft_mlx_init(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		fdf_error(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF")))
		fdf_error(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		fdf_error(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img,
	&(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
	fdf->con_mou = control_init(fdf);
	return (fdf);
}

/*
** mlx_key_hook() программа получает «события»
** от клавиатуры или мыши. Эта функция
** никогда не возвращается. Это бесконечный цикл, который ожидает события,
** а затем вызывает пользовательскую функцию, связанную с этим событием.
** Необходим один параметр - идентификатор соединения mlx_ptr
*/

void			ft_setup_key_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}
