/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:20:30 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/04 17:23:34 by yukravch         ###   ########.fr       */
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

void	ft_free_map(t_map* map, int allocated_rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->matrix)
	{
		while (i < allocated_rows)
		{
			if (map->matrix[i])
				free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	free(map);
}

void    *ft_free_2D_array(char** array)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (array[word])
		word++;
	while (i < word)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
	}

t_map	*ft_malloc_map(int rows, int columns, t_map* map)
{
	int	number;

	number = 0;
	//dynamic memory allocation for structure
	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = columns;
	map->height = rows;

	//memory allocation for y - rows
	map->matrix = (t_point**)malloc(sizeof(t_point*)*rows);
	if (!map->matrix)
	{
		free(map);
		return (NULL);
	}

	//memory allocation for every x line - columns
	while (number < rows)
	{
		map->matrix[number] = (t_point*)malloc(sizeof(t_point)*map->width);
		if (!map->matrix[number])
		{
			ft_free_map(map, number);
			return (NULL);
		}
		number++;
	}
	return (map);
}

t_map   *ft_check_if_rectangle(int fd, t_map* map)
{
        char*   line;
        int     flc; //first line columns, count columns (how much numbers) of the first line
        int     cc; //current count, count columns (how much numbers in the line)
        int     rows = 1;

        line = get_next_line(fd);
        if (!line)
        {
                perror("Error: Empty or damaged file\n");
                close(fd);
                exit(EXIT_FAILURE);
        }
        flc = ft_count_line_numbers(line, ' ');
        free(line);
        while ((line = get_next_line(fd)) != NULL)
        {
                cc = ft_count_line_numbers(line, ' ');
                if (flc != cc)
                {
                        ft_printf("Wrong map format. It should form a rectangle\n");
                        free(line);
                        close(fd);
                        exit(EXIT_FAILURE);
                }
                rows++;
                free(line);
        }
        close(fd);
        map = ft_malloc_map(rows, cc, map);
        if (!map)
        {
                perror("Error: Failed to allocate memory for map\n");
                exit(EXIT_FAILURE);
        }
		map->translate_x = 0;
		map->translate_y = 0;
		map->zoom = 1;
        map->width = cc;
        map->height = rows;
        return (map);
}
