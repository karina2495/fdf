/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:18:48 by vfearles          #+#    #+#             */
/*   Updated: 2019/12/27 16:18:50 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define FT_INT_MAX			((int)2147483647)
# define FT_INT_MIN			((int)-2147483648)

# define TEXT_COLOR			0xFFFFFF
# define BACKGROUND			0x000000

# define AQUA_MARINE		0x7FFFD4
# define INDIGO				0x4B0082
# define DARK_MAGENTA		0x8B008B
# define BEIGE				0xF5F5DC
# define LAVENDER			0xE6E6FA
# define FLORAL_WHITE		0xFFFAF0
# define ALICE_BLUE			0xF0F8FF
# define SEA_GREEN			0x2E8B57
# define OLIVE				0x808000
# define RED				0xFF0000

# define ERR_USAGE			"Usage: ./fdf source_file"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_READING	"Reading error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONTROL		"Control initialization error"
# define ERR_MEM_ALLOC		"FdF: failed to allocate memory\n"

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_0			82
# define NUM_2			84
# define NUM_4			86
# define NUM_5			87
# define NUM_6			88
# define NUM_8			91
# define NUM_PLUS		69
# define NUM_MINUS		78
# define NUM_STAR		67
# define NUM_SLASH		75
# define MAIN_LESS		43
# define MAIN_MORE		47
# define MAIN_ESC		53
# define MAIN_I 		34
# define MAIN_P 		35
# define MAIN_C			8

#endif
