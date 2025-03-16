/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/16 19:48:06 by yukravch         ###   ########.fr       */
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
		while (x < map->width)
		{
			map->matrix[y][x].x = x * zoom;
			map->matrix[y][x].y = y * zoom;
			map->matrix[y][x].z = ft_atoi(array[x]) * zoom;
			map->matrix[y][x].color = 0xFF112233;
			x++;
		}
		y++;
		ft_free_2D_array(array);
	}
	return (map->matrix);
}

void	ft_put_image_to_center(t_map* map)
{
	//1step: get point of  start(x, y) and point of end(x, y) of the image
	int		i;
	int		j;
	t_image_size*	ims;
	
	ims = (t_image_size*)malloc(sizeof(t_image_size));
	if (!ims)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j].x_proj < ims.x_min)
				ims.x_min = map->matrix[i][j].x_proj;
			if (map->matrix[i][j].y_proj < ims.y_min)
				ims.y_min = map->matrix[i][j].y_proj;
			if (map->matrix[i][j].x_proj > ims.x_max)
				ims.x_min = map->matrix[i][j].x_proj;
			if (map->matrix[i][j].y_proj > ims.y_max)
				ims.y_max = map->matrix[i][j].y_proj;
			j++;
		}
	i++;
	}
	ims.height = ims.y_max - ims.y_min;
	ims.width = ims.x_max - ims.x_min;
	
	ims.offset_x = (WIN_WIDTH - ims.width ) / 2 - ims.x_min;
	ims.offset_y = (WIN_HEIGHT - ims.height) / 2 - ims.y_min;
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
			map->matrix[i][j].x_proj = ((map->matrix[i][j].x - map->matrix[i][j].y) * cos(0.523599));
			map->matrix[i][j].x_proj += WIN_WIDTH / 2;
			map->matrix[i][j].y_proj = ((map->matrix[i][j].x + map->matrix[i][j].y) * sin(0.523599) -map->matrix[i][j].z);
			map->matrix[i][j].y_proj += WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
	ft_put_image_to_center(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x_proj += ;
			map->matrix[i][j].y_proj += WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
	return (map);
}


