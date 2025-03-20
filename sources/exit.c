/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:51:36 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 14:08:53 by yukravch         ###   ########.fr       */
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

int	ft_exit_final(t_mlx* mlx, t_map* map, t_hook* hook)
{
	if (mlx->ptr && mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->ptr && mlx->win_ptr)
	{	mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	}
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	ft_free_map(map, map->height);
	free(mlx);
	free(hook);
	return 0;
}
void	ft_exit_mlx(t_mlx *mlx)
{
	free(mlx);
	exit(EXIT_FAILURE);
}

