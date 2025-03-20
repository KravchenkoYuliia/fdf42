/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 13:48:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

double  ft_get_scale(t_map* map)
{
        double  scale_x;
        double  scale_y;
        double  scale;

        scale_x = (WIN_WIDTH / 2) /  map->width;
        scale_y = (WIN_HEIGHT / 2) / map->height;
        scale = fmin(scale_x, scale_y);
        return (scale);
}

void	free_last_file_content(int fd)
{
	char* line;
	line = get_next_line(fd);
	while (line != NULL) {
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

t_point**	ft_initialize_points(int fd, t_map* map)
{
	int	y;
	int	x;
	char**	array;
	char	*line;
	double	scale;

	scale = ft_get_scale(map);
	if (!map || !map->matrix)
	{
		perror("Error: map or matrix is NULL in ft_initialize_points");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit_fd(fd, line, map);
		array = ft_split(line, ' ');
		free(line);
		if (!array)
		{
			perror("Error: Failed to split line\n");
			ft_free_map(map, map->height);
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (!map->matrix[y])
		{
			perror("Error: map->matrix[y] is NULL in ft_initialize_points\n");
		}
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x].x = x * scale;
			map->matrix[y][x].y = y * scale;
			map->matrix[y][x].z = ft_atoi(array[x]) * 6;
			map->matrix[y][x].color = 0xFF112233;
			x++;
		}
		y++;
		ft_free_2d_array(array);
	}
	free_last_file_content(fd);
	return (map->matrix);
}

void    ft_projection(t_map* map)
{		
		t_mlx*	mlx;

		mlx = (t_mlx*)malloc(sizeof(t_mlx));
		if (!mlx)
			return ;
		mlx->img = NULL;
		mlx->ptr = mlx_init();
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
		generate_image(mlx, map);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img, 0, 0);
		t_hook* hook = ft_hooks(mlx, map);
		mlx_loop(mlx->ptr);
		ft_exit(mlx, map, hook);
}

