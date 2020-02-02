/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:27:01 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:18:43 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "math.h"
# include <errno.h>
# define HEIGHT			1080
# define WIDTH			1920
# define RADIAN			0.523599

typedef struct		s_coord
{
	int				z;
	int				color;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_con_mou
{
	int				projection;
	int				zoom;
	double			alf;
	double			bet;
	double			gam;
	float			z_altitude;
	int				x_move;
	int				y_move;
	int				color;
	int				menu;
	char			is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
}					t_con_mou;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				*coords;
	int				*colors;
	int				z_min;
	int				z_max;
	int				z_range;
	size_t			size;
	t_con_mou		*con_mou;
}					t_fdf;

/*
** управление окнами и библиотекой miniLibX
*/

t_fdf				*ft_mlx_init(t_fdf *fdf);
void				ft_setup_key_hook(t_fdf *fdf);

/*
** Инициализация структуры fdf и control
*/

t_con_mou			*control_init(t_fdf *fdf);
t_fdf				*init(void);

/*
** чтение карты и заполение массивов intов
*/

int					read_map(const int fd, t_coord **c_stack, t_fdf *fdf);
void				stack_arrays(t_coord **coords_stack, t_fdf *fdf);
t_coord				*ft_new_coords(char *str);
t_coord				*get_last_coords(t_coord **c_stack);
void				put_new_coords(t_coord **coords_stack, t_coord *new);

/*
** контроль управления через клавиатуру
*/

void				zoom_fdf(int keycode, t_fdf *fdf);
void				color_fdf(int keycode, t_fdf *fdf);
void				change_rot(int keycode, t_fdf *fdf);
void				change_pike(int keycode, t_fdf *fdf);
void				change_proj(int keycode, t_fdf *fdf);

/*
** контроль управления с помощью мыши
*/

int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);

/*
** отрисовка пиксельных линий в окно
*/

int					ft_get_default_color(int z, t_fdf *fdf);
void				put_pixel(t_fdf *fdf, int x, int y, int color);
void				des_line(t_point one, t_point two, t_fdf *fdf, int i);
void				describe(t_fdf *fdf, int x, int y);
void				ft_describe(t_fdf *fdf);
t_point				point_new(int x, int y, t_fdf *fdf);
double				ft_get_percent(int start, int end, int current);
int					ft_line_interpol(int start, int end, double percent);
int					f_color(t_point cur, t_point start, t_point end, t_point d);

/*
** регулировка положения карты в окне
*/

void				rotate_xyz(int *x, int *y, int *z, t_fdf *fdf);
void				ft_iso(int *x, int *y, int z);
t_point				project(int x, int y, t_fdf *fdf);

/*
** дополнительные функции; отрисовка меню управления
*/

void				fdf_error(char *s);
int					key_press(int keycode, void *param);
void				print_menu(t_fdf *fdf, int y);
int					key_press(int keycode, void *param);
int					ft_check_color(const char *tmp, int i, int k);

#endif
