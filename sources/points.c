/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/17 19:55:45 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

t_point**	ft_initialize_points(int fd, t_map* map)
{
	//index to show coordinates of the point in **matrix(just a position in memory to acces the elements of the **matrix)
	int	y;
	int	x;
	char**	array;
	char	*line;

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
			map->matrix[y][x].x = x;
			map->matrix[y][x].y = y;
			map->matrix[y][x].z = ft_atoi(array[x]);
			map->matrix[y][x].color = 0xFF112233;
			x++;
		}
		y++;
		ft_free_2D_array(array);
	}
	return (map->matrix);
}

t_image_size*	ft_put_image_to_center(t_map* map)
{
	//1step: get point of  start(x, y) and point of end(x, y) of the image
	int		i;
	int		j;
	t_image_size*	ims;
	
	ims = (t_image_size*)malloc(sizeof(t_image_size));
	if (!ims)
		return (NULL);
	if (!map || !map->matrix)
	{
		perror("Error: map or matrix is NULL in ft_put image_to_center\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	if (!ims)
	{
		perror("Error: Failed to allocate memory for ims in ft_put_image_to_window\n");
		exit(EXIT_FAILURE);
	}
	ims->x_min = DBL_MAX;
	ims->y_min = DBL_MAX;
	ims->x_max = -DBL_MAX;
	ims->y_max = -DBL_MAX;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j].x_proj < ims->x_min)
				ims->x_min = map->matrix[i][j].x_proj;
			if (map->matrix[i][j].y_proj < ims->y_min)
				ims->y_min = map->matrix[i][j].y_proj;
			if (map->matrix[i][j].x_proj > ims->x_max)
				ims->x_max = map->matrix[i][j].x_proj;
			if (map->matrix[i][j].y_proj > ims->y_max)
				ims->y_max = map->matrix[i][j].y_proj;
			j++;
		}
		i++;
	}
	ims->height = ims->y_max - ims->y_min;
	ims->width = ims->x_max - ims->x_min;
	
	ims->offset_x = (WIN_WIDTH - ims->width ) / 2 - ims->x_min;
	ims->offset_y = (WIN_HEIGHT - ims->height) / 2 - ims->y_min;
	return (ims);
}

void	ft_zoom(t_map* map, t_image_size* ims)
{
	int	i;
	int	j;
	double	scale_x;
	double	scale_y;
	double	scale;
	double	center_x;
	double	center_y;

	printf("BEFORE SCALE: ims->x_min=%f, ims->x_max=%f, ims->y_min=%f, ims->y_max=%f\n", ims->x_min, ims->x_max, ims->y_min, ims->y_max);
	/////DELETE
	if (ims->width <= 0)
		ims->width = 1;
	if (ims->height <= 0)
		ims->height = 1;
	scale_x = (WIN_WIDTH - 100) / ims->width;
	scale_y = (WIN_HEIGHT - 100) / ims->height;
	scale = fmin(scale_x, scale_y);
	printf("SCALE: scale_x=%f, scale_y=%f, selected scale=%f\n", scale_x, scale_y, scale); ///DELETE
	if (scale < 0.1)
		scale = 0.1;
	printf("First point before scale: x_proj = %f, y_proj = %f\n", map->matrix[0][0].x_proj, map->matrix[0][0].y_proj);
	printf("Last point before scale: x_proj = %f, y_proj = %f\n", map->matrix[map->height - 1][map->width - 1].x_proj, map->matrix[map->height - 1][map->width - 1].y_proj);
	center_x = (ims->x_max + ims->x_min) / 2;
	center_y = (ims->y_max + ims->y_min) / 2;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x_proj = (map->matrix[i][j].x_proj - ) * scale + 25;
			map->matrix[i][j].y_proj = (map->matrix[i][j].y_proj - ims->y_min) * scale + 25;
			j++;
		}
		i++;
	}
	printf("First point after scale: x_proj = %f, y_proj = %f\n", map->matrix[0][0].x_proj, map->matrix[0][0].y_proj);
	printf("Last point after scale: x_proj = %f, y_proj = %f\n", map->matrix[map->height - 1][map->width - 1].x_proj, map->matrix[map->height - 1][map->width - 1].y_proj);
}

void	ft_projection(t_map* map)
{
	int		i; //index for y
	int		j; //index for x
	t_image_size*	ims;

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
			//map->matrix[i][j].x_proj += WIN_WIDTH / 2;
			map->matrix[i][j].y_proj = ((map->matrix[i][j].x + map->matrix[i][j].y) * sin(0.523599) - map->matrix[i][j].z);
			//map->matrix[i][j].y_proj += WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
	if (!map || !map->matrix)
	{
		perror("Error: map or matrix is NULL in ft_put image_to_center\n");
		exit(EXIT_FAILURE);
	}
	ims = ft_put_image_to_center(map);
	if (!ims)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x_proj += ims->offset_x;
			map->matrix[i][j].y_proj += ims->offset_y;
			j++;
		}
		i++;
	}
	if (!ims)
	{
		perror("Error: ims is NULL in ft_projection");
	}
	ft_zoom(map, ims);
	ft_start_drawing(map, ims);
}
