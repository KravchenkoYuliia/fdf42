/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:50:53 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_map	*ft_initialize_map(int fd, t_map *map)
{
	t_fd	*text;

	text = (t_fd *)malloc(sizeof(t_fd));
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
	return (map);
}
void    ft_put_points_to_struct(char **array, int y)
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
	char**	array;

	y = 0;
	while (y < map->height)
	{
		text->line = get_next_line(fd);
		if (!text->line)
			ft_exit_fd(fd, text->line, map);
		array = ft_split(text->line, ' ');
		free(text->line);
		if (!array)
		{
			perror("Error: Failed to split line\n");
			ft_exit_fd(fd, text->line, map);
		}
        ft_put_points_to_struct(array, y);
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

