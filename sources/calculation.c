/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 16:40:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

double	ft_get_scale(t_map *map)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = (WIN_WIDTH / 2) / map->width;
	scale_y = (WIN_HEIGHT / 2) / map->height;
	scale = fmin(scale_x, scale_y);
	return (scale);
}

void	ft_projection(t_map *map)
{
	int		i;
	int		j;

	map->offset_x = (WIN_WIDTH / 2) - map->center_x;
	map->offset_y = (WIN_HEIGHT - map->center_y) / 2;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
				map->matrix[i][j].x_proj = (((map->matrix[i][j].x * map->zoom)
						- (map->matrix[i][j].y * map->zoom)) * cos(0.523599));
				map->matrix[i][j].x_proj += map->offset_x;
				map->matrix[i][j].y_proj = (((map->matrix[i][j].x * map->zoom)
						+ (map->matrix[i][j].y * map->zoom)) * sin(0.523599)
					- map->matrix[i][j].z);
				map->matrix[i][j].y_proj += map->offset_y;
				j++;
		}
		i++;
	}
}
