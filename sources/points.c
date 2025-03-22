/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 13:59:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"



void	ft_initialize_points(int fd, t_map* map)
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
			ft_exit_fd(fd, line, map);
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
}

void    ft_initialize_mlx(t_map* map)
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
			ft_exit_mlx(mlx);
		}
		mlx->win_ptr = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "FdF"); //create a new window
		if (!mlx->win_ptr)
		{	
			perror("Error: Failed to create a new window\n");
			ft_exit_mlx(mlx);
		}
		ft_generate_image(mlx, map);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img, 0, 0);
		t_hook* hook = ft_hooks(mlx, map);
		mlx_loop(mlx->ptr);
		ft_exit_final(mlx, map, hook);
}

