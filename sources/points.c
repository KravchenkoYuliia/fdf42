/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/04 17:19:57 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point**	ft_initialize_points(int fd, t_map* map)
{
	//index to show coordinates of the point in **matrix(just a position in memory to acces the elements of the **matrix)
	int	y;
	int	x;
	char**	array;
	char	*line;

	y = 0;
	ft_printf("map->height = %d\n", map->height);
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			perror("Error: line is NULL in ft_inintialize_points\n");
			close(fd);
			ft_free_map(map, map->height);
			exit(EXIT_FAILURE);
		}
		//ft_printf("line number %d: %s\n", y, line);
		array = ft_split(line, ' ');
		free(line);
		if (!array)
		{
			perror("Error: Failed to split line\n");
			ft_free_map(map, map->height);
			close(fd);
			exit(EXIT_FAILURE);
		}
		x = 0;
		//ft_printf("before x loop: x: %d, y:%d\n", x, y);
		while (x < map->width)
		{
			map->matrix[y][x].x = x * zoom;
			map->matrix[y][x].y = y * zoom;
			map->matrix[y][x].z = ft_atoi(array[x]) * zoom;
			map->matrix[y][x].color = 0xFF112233;
			//ft_printf("coordinates of the point: (%d, %d)\nheight oaf the point: %d\n\n", map->matrix[y][x].x, map->matrix[y][x].y, map->matrix[y][x].z);
			x++;
		}
		y++;
		ft_free_2D_array(array);
	}
	return (map->matrix);
}

t_map*  ft_projection(t_map* map)
{
	int	i; //index for y
	int	j; //index for x

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x_proj = (int)((map->matrix[i][j].x - map->matrix[i][j].y) * cos(0.523599));
			map->matrix[i][j].x_proj += WIN_WIDTH / 2;
			map->matrix[i][j].y_proj = (int)((map->matrix[i][j].x + map->matrix[i][j].y) * sin(0.523599) -map->matrix[i][j].z);
			map->matrix[i][j].y_proj += WIN_HEIGHT / 2;
			ft_printf("x':%d y':%d\n", map->matrix[i][j].x_proj, map->matrix[i][j].y_proj);
			j++;
		}
		ft_printf("\n");
		ft_printf("new line n %d\n\n", i);
		i++;
	}
	return (map);
}
