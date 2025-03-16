/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/16 19:43:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "mlx_int.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <floats.h>

#define	zoom 20
#define	WIN_WIDTH 1920
#define	WIN_HEIGHT 1080

//struct for every point of map
typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	color;
	double	x_proj;
	double	y_proj;//points after transformation 3D(x, y, z) to 2D(x', y')
} t_point;

typedef	struct	s_map{
	int	y;
	int	x;
	int	width; //numbers in line (x-columns)
	int	height; //number of lines (y-rows)
	t_point**	matrix; //2D-array struct for stocking z-values (height and color of each x,y point)
} t_map;

typedef struct	s_image_size{
	double  x_min = DBL_MAX;
	double  y_min = DBL_MAX;
	double  x_max = DBL_MIN;
	double  y_max = DBL_MIN;
	double	height;
	double	width;
	double	offset_x;
	double	offset_y;	
}

typedef struct s_mlx{
	void*	ptr;
	void*	win_ptr;
	void*	img;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char*	bits_buff;	
} t_mlx;

int		ft_check_if_fdf(char* filename);
void		ft_fdf(char* filename);
int		ft_count_line_numbers(char* str, char c);
t_map*		ft_check_if_rectangle(int fd, t_map* map);
t_map*		ft_malloc_map(int rows, int columns, t_map* map);
void*		ft_free_2D_array(char** array);
void		ft_free_map(t_map* map, int allocated_rows);
t_point**	ft_initialize_points(int fd, t_map* map);
t_map*		ft_projection(t_map* map);
void		ft_pixel_put(t_mlx* mlx, int x, int y, int color);
void		ft_start_drawing(t_map* map);
void		ft_hooks(t_mlx* mlx, t_map* map);
int		ft_key_press(int keycode, t_mlx* mlx);

#endif
