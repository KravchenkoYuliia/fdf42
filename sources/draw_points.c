/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:02:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/05 11:26:23 by yukravch         ###   ########.fr       */
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

void	ft_draw_points(t_map* map)
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
	mlx->win_ptr = mlx_new_window(mlx->ptr, 1000, 1000, "FdF"); //create a new window
	if (!mlx->win_ptr)
	{	
		perror("Error: Failed to create a new window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->ptr, 1000, 1000); //create a new image on the window
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
	if (!(map->matrix[i][j].x_proj >= 0 && map->matrix[i][j].x_proj <= 1000 && map->matrix[i][j].y_proj >= 0 && map->matrix[i][j].y_proj <= 1000))
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
	ft_pixel_put(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, 0xFFFFFF);
	j++;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
		 	ft_pixel_put(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img,  0, 0);
	ft_hooks(mlx);
	mlx_loop(mlx->ptr);
	free(mlx);
}
