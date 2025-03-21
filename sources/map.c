/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:20:30 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 17:05:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_line_numbers(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c && i != 0)
			count++;
		if ((str[i + 1] == '\0') && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

t_map	*ft_malloc_map(int rows, int columns, t_map *map)
{
	int	number;

	number = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = columns;
	map->height = rows;
	map->matrix = (t_point **)malloc(sizeof(t_point *) * rows);
	if (!map->matrix)
	{
		free(map);
		return (NULL);
	}
	while (number < rows)
	{
		map->matrix[number] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->matrix[number])
		{
			ft_free_map(map, number);
			return (NULL);
		}
		number++;
	}
	return (map);
}

void	ft_check_if_rectangle(int fd, t_fd *text)
{
	t_map	*null;

	null = NULL;
	text->rows = 1;
	text->line = get_next_line(fd);
	if (!text->line)
		ft_exit_fd(fd, text->line, null);
	text->flc = ft_count_line_numbers(text->line, ' ');
	free(text->line);
	while (1)
	{
		text->line = get_next_line(fd);
		if (text->line == NULL)
			break ;
		text->cc = ft_count_line_numbers(text->line, ' ');
		if (text->flc != text->cc)
		{
			ft_printf("Wrong map format. It should form a rectangle\n");
			ft_exit_fd(fd, text->line, null);
		}
		text->rows++;
		free(text->line);
	}
	close(fd);
}
