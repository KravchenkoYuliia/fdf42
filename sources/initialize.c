/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:50:53 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 14:02:36 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (map);
}



