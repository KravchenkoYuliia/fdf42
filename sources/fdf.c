/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:54:51 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/17 09:46:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_fdf(char* filename)
{
	t_map*		map;
	t_point**	matrix;
	int		fd;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{	
		perror("Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	map = ft_check_if_rectangle(fd, map);
	if (!map)
	{
		perror("Error: Failed to allocate memory for map\n");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	matrix = ft_initialize_points(fd, map);
	if (!matrix)
	{
		perror("Error: Failed to initialize points\n");
		ft_free_map(map, map->height);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	ft_projection(map);
//	ft_start_drawing(map);
}
