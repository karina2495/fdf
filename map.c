/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:17:48 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:17:50 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Создание новой координаты
*/

void			put_new_coords(t_coord **coords_stack, t_coord *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Выделяем память под список t_coord
** и записываем туда координату параметра 'z'
** - через atoi и цвет, если он был передан, - с помощью atoi_base.
** Если цвет отсвутствует - значение принимается равным '-1'.
*/

t_coord			*ft_new_coords(char *str)
{
	t_coord		*coordin;
	int			i;

	i = 0;
	if (!(coordin = (t_coord *)ft_memalloc(sizeof(t_coord))))
		fdf_error(ERR_MEM_ALLOC);
	if ((i = ft_check_color(str, i, 0)) == -1)
		fdf_error(ERR_MAP);
	coordin->z = ft_atoi(str);
	coordin->color = i ? ft_atoi_base(str + i, 16) : -1;
	coordin->next = NULL;
	return (coordin);
}

/*
** Считываем построчно файл с помощью get_next_line, обрезаем пробельные символы
** через strsplit. Из полученного двумерного массива по одному аргументу
** вынимаем координаты 'z'. Получаем стэк из координат вершин и стэк для цвета.
*/

int				read_map(const int fd, t_coord **c_stack, t_fdf *fdf)
{
	char		*line;
	int			rez;
	char		**coord;
	int			i;

	while ((rez = get_next_line(fd, &line)) == 1)
	{
		if (!(coord = ft_strsplit(line, ' ')))
			fdf_error(ERR_MAP_READING);
		i = -1;
		while (coord[++i])
			put_new_coords(c_stack, ft_new_coords((coord[i])));
		if (fdf->height == 0)
			fdf->width = i;
		if (fdf->width != (int)ft_wordcount(line, ' '))
			fdf_error(ERR_MAP);
		ft_clear_mass(&coord);
		ft_strdel(&line);
		fdf->height++;
	}
	if (!(*c_stack))
		fdf_error(ERR_MAP);
	stack_arrays(c_stack, fdf);
	return (rez);
}
