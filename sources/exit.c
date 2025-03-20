/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:51:36 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 12:19:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_exit_fd(int fd, char *line)
{
    if (!line)
        perror("Error: Empty or damaged file\n");
    if (line)
	    free(line);
    if (fd)
        close(fd);
    exit(EXIT_FAILURE);
}
