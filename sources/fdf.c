/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:54:51 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(char *filename)
{
	t_map	*map;
	int		fd;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit_perror("Error: Can't open file\n");
	map = ft_initialize_map(fd, map);
	if (!map)
		ft_exit_perror("Error: Failed to allocate memory for map\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit_perror("Error: Can't open file\n");
	ft_initialize_points(fd, map);
	ft_initialize_mlx(map);
}
