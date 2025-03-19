/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/19 18:08:55 by yukravch         ###   ########.fr       */
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
	//index to show coordinates of the point in **matrix(just a position in memory to acces the elements of the **matrix)
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
		ft_free_2D_array(array);
	}
	free_last_file_content(fd);
	return (map->matrix);
}
void    ft_projection(t_map* map)
{
        int             i; //index for y
        int             j; //index for x
        double          scale;
        double  map_center_x;
        double  map_center_y;
        double  offset_x;
        double  offset_y;

        scale = ft_get_scale(map) * map->zoom;
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
                        map->matrix[i][j].x_proj = ((map->matrix[i][j].x - map->matrix[i][j].y) * cos(0.523599));
                        map->matrix[i][j].x_proj += offset_x;
                        map->matrix[i][j].y_proj = ((map->matrix[i][j].x + map->matrix[i][j].y) * sin(0.523599) - map->matrix[i][j].z);
                        map->matrix[i][j].y_proj += offset_y;
                        j++;
                }
                i++;
        }
        if (!map || !map->matrix)
        {
                perror("Error: map or matrix is NULL in ft_put image_to_center\n");
                exit(EXIT_FAILURE);
        }
        i = 0;
        ft_start_drawing(map);
}

