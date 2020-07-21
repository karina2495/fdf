/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:00:15 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:17:43 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Программа принимает только одну карту в качестве аргумента.
** Инициализация структуры fdf и чтение файла через файловый дескриптор.
** Инициализация функций библиотеки mlx, заполнение окна пикселями.
** Подключение событий клавиатуры/мыши.
*/

int					main(int ac, char **av)
{
	int				fd;
	t_fdf			*fdf;
	t_coord			*c_stack;

	c_stack = NULL;
	if (ac != 2)
		fdf_error(ERR_USAGE);
	if (!((fd = open(av[1], O_RDONLY)) >= 0))
		fdf_error(ERR_MAP);
	if (!(fdf = init()) || read_map(fd, &c_stack, fdf) == -1)
		fdf_error(ERR_MAP_READING);
	close(fd);
	ft_mlx_init(fdf);
	ft_describe(fdf);
	ft_setup_key_hook(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
