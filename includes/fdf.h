/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 13:25:36 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/minilibx-linux/mlx_int.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>

# define WIN_WIDTH 1820
# define WIN_HEIGHT 880

typedef struct s_fd{
        int flc;
        int cc;
        int rows;
        char *line;

}       t_fd;

typedef struct s_point{
	int		x;
	int		y;
	int		z;
	int		color;
	double	x_proj;
	double	y_proj;
}	t_point;

typedef struct s_map{
	int		translate_x;
	int		translate_y;
	int		width;
	int		height;
	double	zoom;
	t_point	**matrix;
}	t_map;

typedef struct s_mlx{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*ptr;
	void	*win_ptr;
	void	*img;
	char	*bits_buff;
}	t_mlx;

typedef struct s_hook {
	t_mlx	*mlx;
	t_map	*map;
}	t_hook;

int		ft_exit(t_mlx *mlx, t_map *map, t_hook *hook);
int		check_if_fdf(char *filename);
int		ft_count_line_numbers(char *str, char c);
int		ft_key_press(int keycode, t_hook *param);
void	ft_check_if_rectangle(int fd, t_fd *text);
t_map   *ft_initialize_map(int fd, t_map *map);
t_map	*ft_malloc_map(int rows, int columns, t_map *map);
t_hook	*ft_hooks(t_mlx *mlx, t_map *map);
t_point	**ft_initialize_points(int fd, t_map *map);
void	ft_fdf(char *filename);
void	*ft_free_2d_array(char **array);
void	ft_free_map(t_map *map, int allocated_rows);
void	ft_projection(t_map *map);
void	ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void	ft_start_drawing(t_map *map);
void	ft_exit_fd(int fd, char *line);
void	generate_image(t_mlx *mlx, t_map *map);
double	ft_get_scale(t_map *map);

#endif
