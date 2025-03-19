/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:02:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/19 16:41:01 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


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

void	ft_draw_lines(t_mlx* mlx, t_map* map, double x1, double y1, double x2, double y2) //first and last points of the line
{
	double	pixels;
	double	d_x; //distance on x axis between start and end points
	double	d_y; //distance on y axis between start ans end points
	double	start_x = x1 - (WIN_WIDTH / 4) + map->translate_x;
	double	start_y = y1 - (WIN_HEIGHT / 4) + map->translate_y;

	d_x = x2 - x1;
	d_y = y2 - y1;
	pixels = sqrt((d_x * d_x) + (d_y * d_y)); // mathematical formula for distance to get the number of pixels from start to end point
	d_x /= pixels; //by how many pixels we need to shift coordinates on X axis by each step
	d_y /= pixels; //by how many pixels we need to shift coordinates on Y axis by each step
	while ((int)pixels)
	{
		ft_pixel_put(mlx, start_x, start_y, 0xFFFFFF);
		start_x += d_x;
		start_y += d_y;
		pixels--;
	}
}

void	ft_get_points_to_draw_a_line(t_mlx* mlx, t_map* map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width-1)
				ft_draw_lines(mlx, map, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, map->matrix[i][j+1].x_proj, map->matrix[i][j+1].y_proj);
			if (i < map->height-1)
				ft_draw_lines(mlx, map, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, map->matrix[i+1][j].x_proj, map->matrix[i+1][j].y_proj);
			j++;
		}
		i++;
	}
}

void generate_image(t_mlx* mlx, t_map* map)
{
	int             i; //index for y
	int             j; //index for x
	double          scale;
	double  map_center_x;
	double  map_center_y;
	double  offset_x;
	double  offset_y;
	
	scale = ft_get_scale(map);
	map_center_x = map->width / 2;
	map_center_y = map->height / 2;
	offset_x = (WIN_WIDTH / 2) - map_center_x;
	offset_y = (WIN_HEIGHT - map_center_y) / 2;
	i = 0;
	while (i < map->height)
	{
			j = 0;
			if (!map || !map->matrix || !map->matrix[i])
			{
					perror("Error: !map->matrix in  ft_projection\n");
			}
			while (j < map->width)
			{
					map->matrix[i][j].x_proj = (((map->matrix[i][j].x * map->zoom) - (map->matrix[i][j].y * map->zoom)) * cos(0.523599));
					map->matrix[i][j].x_proj += offset_x;
					map->matrix[i][j].y_proj = (((map->matrix[i][j].x * map->zoom) + (map->matrix[i][j].y * map->zoom)) * sin(0.523599) - map->matrix[i][j].z);
					map->matrix[i][j].y_proj += offset_y;
					j++;
			}
			i++;
	}
	
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img);

	mlx->img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT); //create a new image on the window
	if (!mlx->img)
	{
		perror("Error: Failed to create a new image on the window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->bits_buff = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	if (!mlx->bits_buff)
	{
		perror("Error: Failed to get image data address");
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	if (!map || !map->matrix || map->height <= 0 || map->width <= 0)
	{
		perror("Error: Invalid map structure");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	ft_get_points_to_draw_a_line(mlx, map);
}

