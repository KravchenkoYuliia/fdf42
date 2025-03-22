/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:02:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 13:58:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_pixel_put(t_mlx* mlx, int x, int y, int color)
{
	char*	dest;

	if (x < 0 || y < 0 || x>= WIN_WIDTH || y >= WIN_HEIGHT) //window size
		return ;
	if (!mlx->bits_buff)
	{
		perror("Error: mlx->bits_buff is NULL\n");
		return ;
	}
	dest = mlx->bits_buff + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8)); //count pixel's position
	*(unsigned int *)dest = color; // 32 bites = 4 bytes
}

void	ft_draw_lines_x(t_mlx* mlx, t_map* map, int i, int j)
{
	double	pixels;
	double	d_x;
	double	d_y;
	double	start_x;
	double	start_y;

	d_x = map->matrix[i][j + 1].x_proj - map->matrix[i][j].x_proj;
	d_y = map->matrix[i][j + 1].y_proj- map->matrix[i][j].y_proj;
	pixels = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pixels;
	d_y /= pixels;
	start_x = map->matrix[i][j].x_proj - (WIN_WIDTH / 4) + map->translate_x;
	start_y = map->matrix[i][j].y_proj - (WIN_HEIGHT / 4) + map->translate_y;
	while ((int)pixels)
	{
		ft_pixel_put(mlx, start_x, start_y, 0xFFFFFF);
		start_x += d_x;
		start_y += d_y;
		pixels--;
	}
}

void	ft_draw_lines_y(t_mlx* mlx, t_map* map, int i, int j)
{
	double	pixels;
	double	d_x;
	double	d_y;
	double	start_x;
	double	start_y;

	d_x = map->matrix[i + 1][j].x_proj - map->matrix[i][j].x_proj;
	d_y = map->matrix[i + 1][j].y_proj- map->matrix[i][j].y_proj;
	pixels = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pixels;
	d_y /= pixels;
	start_x = map->matrix[i][j].x_proj - (WIN_WIDTH / 4) + map->translate_x;
	start_y = map->matrix[i][j].y_proj - (WIN_HEIGHT / 4) + map->translate_y;
	while ((int)pixels)
	{
		ft_pixel_put(mlx, start_x, start_y, 0xFFFFFF);
		start_x += d_x;
		start_y += d_y;
		pixels--;
	}
}
void	ft_get_points_to_draw_a_line(t_mlx *mlx, t_map *map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width - 1)
				ft_draw_lines_x(mlx, map, i, j);
			if (i < map->height-1)
				ft_draw_lines_y(mlx, map, i, j);
			j++;
		}
		i++;
	}
}



void	ft_generate_image(t_mlx *mlx, t_map *map)
{
	ft_projection(map);
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img)
	{
		perror("Error: Failed to create a new image on the window\n");
		ft_exit_mlx(mlx);
	}
	mlx->bits_buff = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->bits_buff)
	{
		perror("Error: Failed to get image data address");
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
		ft_exit_mlx(mlx);
	}
	if (!map || !map->matrix || map->height <= 0 || map->width <= 0)
	{
		perror("Error: Invalid map structure");
		ft_exit_mlx(mlx);
	}
	ft_get_points_to_draw_a_line(mlx, map);
}
