/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:51:36 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 13:47:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_exit_fd(int fd, char *line, t_map *map)
{
    if (!line)
        perror("Error: Line is NULL\n");
    if (line)
	    free(line);
    if (fd)
        close(fd);
    if (map)
	    ft_free_map(map, map->height);
    exit(EXIT_FAILURE);
}
