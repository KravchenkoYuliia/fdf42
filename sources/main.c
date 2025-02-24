/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:32:20 by yukravch          #+#    #+#             */
/*   Updated: 2025/02/23 14:38:08 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_if_fdf(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i > 4 && filename[i-1] == 'f' && filename[i-2] == 'd' && filename[i-3] == 'f' && filename[i-4] == '.')
		return (1);
	return (0);
}

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

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		result;
	char	sign;

	result = 0;
	sign = 1;
	str = (char *)nptr;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}

void	ft_free_2D_array(char **array, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

t_map	ft_malloc_map(int fd, char* filename, int rows, int columns)
{
	t_map*	map;
	int	number;

	number = 0;
	//dynamic memory allocation for structure
	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = columns;
	map->height = rows;

	//memory allocation for y - rows
	map->matrix = (int**)malloc(sizeof(int*)*rows);
	if (!map->matrix)
	{
		free(map);
		return (NULL);
	}
	
	//memory allocation for every x line - columns
	while (number < rows)
	{
		map->matrix[number] = (int*)malloc(sizeof(int)*map->width);
		if (!map->matrix[number])
		{
			ft_free_2D_array(map->matrix, number);
			free(map);
			return (NULL);
		}
		number++;
	}
}

void	ft_check_if_rectangle(int fd, char* filename)
{
        char*   line;
	int	flc; //first line columns, count columns (how much numbers) of the first line
	int	cc; //current count, count columns (how much numbers in the line)
	char**	array;
	int	rows = 1;
/*
 *
 * array[y][x]:
 *
 * array[0][1]
 * array[0][2]...
 */
	
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Empty file");
		exit(0);
	}
	flc = ft_count_line_numbers(line, ' ');
	array = ft_split(line, ' ');
        while ((line = get_next_line(fd)) != NULL)
	{
		cc = ft_count_line_numbers(line, ' ');
		if (flc != cc)
		{
			ft_printf("Wrong map format. It should form a rectangle\n");
			exit(0);
		}
		array = ft_split(line, ' ');
		rows++;

	}
	ft_printf("Valid map format\n rows: %d\n", rows);
	close(fd);
	ft_malloc_map(fd, filename, rows, cc);
}

void	check_errors(char *filename)
{
	char	buffer[1];
	int	read_return;
	int	fd;
	
	fd = open(filename, O_RDONLY);
	//ne peut pas ouvrir le fichier(pas de droit/fichier n'existe pas/c'est un dossier)
	if (fd == -1)
	{
		ft_printf("Can't open file");
		exit(0);
	}
	read_return = read(fd, buffer, 1);
	//erreur de lecture/le fichier a ete ouvert de maniere incorrecte/fichier endommage)
	if (read_return < 0)
	{
		ft_printf("Not valid file");
		exit(0);
	}
	//pas un erreur, fichier existe, mais a 0 bytes dedans, pas de donne a lire
	else if (read_return == 0)
	{
		ft_printf("The file is empty");
		exit(0);
	}
	else
	{
		close(fd);
		ft_check_if_rectangle(fd, filename);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Wrong number of arguments. Give 1 file, please.\n");
		exit(0);
	}
	else if (!check_if_fdf(argv[1]))
		ft_printf("Wrong file format. The right format: filename.fdf\n");
	else
		check_errors(argv[1]);
	return (0);
}
