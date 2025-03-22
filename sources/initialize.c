/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:50:53 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 16:34:15 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_initialize_map(int fd, t_map *map)
{
    t_fd *text;

    text = (t_fd *)malloc(sizeof(t_fd));
    if (!text)
        return (NULL);
	
    ft_check_if_rectangle(fd, text);
	map = ft_malloc_map(text->rows, text->cc, map);
	if (!map)
	{
		perror("Map is not allocated in ft_initialize_map\n");
		exit(EXIT_FAILURE);
	}
	map->width = text->cc;
	map->height = text->rows;
	free(text);
	map->translate_x = 0;
	map->translate_y = 0;
	map->zoom = 1;
    map->scale = ft_get_scale(map);
    map->center_x = map->width / 2;
	map->center_y = map->height / 2;
	return (map);
}

void    ft_put_points_to_struct(t_map *map, int y, char **array)
{
    int x;
    
    x = 0;
	while (x < map->width)
	{
		map->matrix[y][x].x = x * map->scale;
		map->matrix[y][x].y = y * map->scale;
		map->matrix[y][x].z = ft_atoi(array[x]) * 6;
		x++;
	}
}
void	ft_initialize_points(int fd, t_map* map)
{
	int	y;
	char**	array;
	char	*line;

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
        ft_put_points_to_struct(map, y, array);
		y++;
		ft_free_2d_array(array);
	}
	free_last_file_content(fd);
}
void    ft_initialize_mlx(t_map* map)
{		
		t_mlx*	mlx;
        t_hook* hook;
        
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
		hook = ft_hooks(mlx, map);
		mlx_loop(mlx->ptr);
		ft_exit_final(mlx, map, hook);
}



