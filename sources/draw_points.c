/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:02:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/16 17:39:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_pixel_put(t_mlx* mlx, int x, int y, int color)
{
	char*	dest;

	if (x < 0 || y < 0 || x>= 1000 || y >= 1000) //window size
		return ;
	dest = mlx->bits_buff + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8)); //count pixel's position
	*(unsigned int *)dest = color; // 32 bites = 4 bytes
}

void	ft_draw_lines(t_mlx* mlx, double x1, double y1, double x2, double y2) //first and last points of the line
{
	double	pixels;
	double	d_x; //distance on x axis between start and end points
	double	d_y; //distance on y axis between start ans end points
	//double	pixel_x;
	//double	pixel_y;

	d_x = x2 - x1;
	d_y = y2 - y1;
	pixels = sqrt((d_x * d_x) + (d_y * d_y)); // mathematical formula for distance to get the number of pixels from start to end point
	d_x /= pixels; //by how many pixels we need to shift coordinates on X axis by each step
	d_y /= pixels; //by how many pixels we need to shift coordinates on Y axis by each step
	while ((int)pixels)
	{
		ft_pixel_put(mlx, x1, y1, 0xFFFFFF);
		x1 += d_x;
		y1 += d_y;
		pixels--;
	}
}

void	ft_get_points_to_draw_a_line(t_mlx* mlx, t_map* map)
{
	int	j;
	int	i;

	i = 0;
//	ft_pixel_put(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, 0xFFFFFF);
//	j++;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width-1)
				ft_draw_lines(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, map->matrix[i][j+1].x_proj, map->matrix[i][j+1].y_proj);
			if (i < map->height-1)
				ft_draw_lines(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, map->matrix[i+1][j].x_proj, map->matrix[i+1][j].y_proj);
			j++;
		}
		i++;
	}
}

void	ft_start_drawing(t_map* map)
{
	t_mlx*	mlx;
	int	i = 0; //index for y
	int	j = 0; //index for x

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!mlx)
		return ;
	mlx->ptr = mlx_init(); //connection with server, display
	if (!mlx->ptr)
	{
		perror("Error: Failed to initialize mlx->ptr");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->win_ptr = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "FdF"); //create a new window
	if (!mlx->win_ptr)
	{	
		perror("Error: Failed to create a new window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT); //create a new image on the window
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
	if (!(map->matrix[i][j].x_proj >= 0 && map->matrix[i][j].x_proj <= WIN_WIDTH && map->matrix[i][j].y_proj >= 0 && map->matrix[i][j].y_proj <= WIN_HEIGHT))
	{
		perror("Error: Invalid map size");
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
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img, map->matrix[0][0].x_proj, map->matrix[0][0].y_proj);
	ft_hooks(mlx, map);
	mlx_loop(mlx->ptr);
	free(mlx);
}
