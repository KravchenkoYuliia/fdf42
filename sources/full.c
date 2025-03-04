/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:32:20 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/04 16:17:26 by yukravch         ###   ########.fr       */
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

void	*ft_free_2D_array(char** array)
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

t_map	*ft_check_if_rectangle(int fd, t_map* map)
{
        char*   line;
	int	flc; //first line columns, count columns (how much numbers) of the first line
	int	cc; //current count, count columns (how much numbers in the line)
	int	rows = 1;
	
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
	map->width = cc;
	map->height = rows;
	return (map);
}

t_point**	ft_initialize_points(int fd, t_map* map)
{
	//index to show coordinates of the point in **matrix(just a position in memory to acces the elements of the **matrix)
	int	y;
	int	x;
	char**	array;
	char	*line;

	y = 0;
	ft_printf("map->height = %d\n", map->height);
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			perror("Error: line is NULL in ft_inintialize_points\n");
                        close(fd);
                        ft_free_map(map, map->height);
                        exit(EXIT_FAILURE);
		}
		//ft_printf("line number %d: %s\n", y, line);
		array = ft_split(line, ' ');
		free(line);
		if (!array)
                {
                        perror("Error: Failed to split line\n");
                        ft_free_map(map, map->height);
                        close(fd);
                        exit(EXIT_FAILURE);
                }
		x = 0;
		//ft_printf("before x loop: x: %d, y:%d\n", x, y);
		while (x < map->width)
		{
			map->matrix[y][x].x = x * zoom;
			map->matrix[y][x].y = y * zoom;
			map->matrix[y][x].z = ft_atoi(array[x]) * zoom;
			map->matrix[y][x].color = 0xFF112233;
			//ft_printf("coordinates of the point: (%d, %d)\nheight oaf the point: %d\n\n", map->matrix[y][x].x, map->matrix[y][x].y, map->matrix[y][x].z);
			x++;
		}
		y++;
		ft_free_2D_array(array);
	}
	return (map->matrix);
}

t_map*	ft_projection(t_map* map)
{
	int		i; //index for y
	int		j; //index for x

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x_proj = (int)((map->matrix[i][j].x - map->matrix[i][j].y) * cos(0.523599));
			map->matrix[i][j].x_proj += WIN_WIDTH / 2;
			map->matrix[i][j].y_proj = (int)((map->matrix[i][j].x + map->matrix[i][j].y) * sin(0.523599) -map->matrix[i][j].z);
			map->matrix[i][j].y_proj += WIN_HEIGHT / 2;
			ft_printf("x':%d y':%d\n", map->matrix[i][j].x_proj, map->matrix[i][j].y_proj);
			j++;
		}
		ft_printf("\n");
		ft_printf("new line n %d\n\n", i);
		i++;
	}
	return (map);
		
}

void	ft_pixel_put(t_mlx* mlx, int x, int y, int color)
{
	char*	dest;

	if (x < 0 || y < 0 || x>= 1000 || y >= 1000) //window size
	       return ;
	dest = mlx->bits_buff + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8)); //count pixel's position
	*(unsigned int *)dest = color; // 32 bites = 4 bytes
}

/*
void	slope_less_than_one(t_map* map, t_mlx* mlx, int dx, int dy)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * dy - dx;
	mlx_pixel_put(mlx->ptr, mlx->win_ptr, map->x_proj, map->y_proj, map->matrix[i][j].color);
	while (i < dx)
	{
		map->x_proj += 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			map->y_proj += 1;
			p = p + 2 * dy - 2 * dx;
		}
	while (i < map->height)
	{
		while (j < map->width)
		{
		mlx_pixel_put(mlx->ptr, mlx->win_ptr, map->x_proj, map->y_proj, map->matrix[i][j].color);
		i++;
	}
}

void	slope_bigger_than_one(t_map* map, t_mlx* mlx, int dx, int dy)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * dx - dy;
	mlx_pixel_put(mlx->ptr, mlx->win_ptr, map->x_proj, map->y_proj, map->matrix[i][j].color);
	while (i < dy)
	{
		map->y_proj += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			map->x_proj += 1;
			p = p + 2* dx - 2 * dy;
		}
		mlx_pixel_put(mlx->ptr, mlx->win_ptr, map->x_proj, map->y_proj, map->matrix[i][j].color);
		i++;
	}
}

void	ft_draw_lines(t_map* map)
{
	t_mlx*	mlx;
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = 0;
	j = 0;
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!mlx)
		return ;

	mlx->ptr = mlx_init(); //connection with server, display
	if (!mlx->ptr)
	{	
		perror("Error: Failed to initialize mlx->ptr");	
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->win_ptr = mlx_new_window(mlx->ptr, 1000, 1000, "FdF"); //create a new window
	if (!mlx->win_ptr)
	{
		perror("Error: Failed to create a new window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->ptr, 1000, 1000); //create a new image on the window
	if (!mlx->img)				       
	{
		perror("Error: Failed to create a new image on the window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
			dx = map->matrix[i][j].x - map->matrix[i][j+1].x;
			dy = map->matrix[i][j].y - map->matrix[i][j+1].y;
			if (abs(dx) > abs(dy))
				slope_smaller_than_one(map, mlx, dx, dy);
			else
				slope_bigger_than_one(map, mlx, dx, dy);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img, j, i);
	mlx_loop(mlx->ptr);
}
*/

void	ft_draw_points(t_map* map)
{
	t_mlx*	mlx;
	int	i = 0; //index for y
	int	j = 0; //index for x

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!mlx)
		return ;
	mlx->ptr = mlx_init(); //connection with server, display
	if (!mlx->ptr)
	{	
		perror("Error: Failed to initialize mlx->ptr");	
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->win_ptr = mlx_new_window(mlx->ptr, 1000, 1000, "FdF"); //create a new window
	if (!mlx->win_ptr)
	{
		perror("Error: Failed to create a new window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->ptr, 1000, 1000); //create a new image on the window
	if (!mlx->img)				       
	{
		perror("Error: Failed to create a new image on the window\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	mlx->bits_buff = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	if (!mlx->bits_buff)
	{
		perror("Error: Failed to get image data address");
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
		free(mlx);
		exit(EXIT_FAILURE);
	}

	if (!(map->matrix[i][j].x_proj >= 0 && map->matrix[i][j].x_proj <= 1000 && map->matrix[i][j].y_proj >= 0 && map->matrix[i][j].y_proj <= 1000))
	{
		perror("Error: Invalid map size");
		free(mlx);
		exit(EXIT_FAILURE);
	}
	if (!map || !map->matrix || map->height <= 0 || map->width <= 0)
	{
		perror("Error: Invalid map structure");
		free(mlx);
		exit(EXIT_FAILURE);
	}

	ft_pixel_put(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, 0xFFFFFF);
	j++;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_pixel_put(mlx, map->matrix[i][j].x_proj, map->matrix[i][j].y_proj, 0xFFFFFF);
			ft_printf("%d %d\n", map->matrix[i][j].x_proj, map->matrix[i][j].y_proj);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img,  0, 0);
	mlx_loop(mlx->ptr);
	free(mlx);
}

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
	map = ft_projection(map);
	if (!map)
	{
		perror("Error: Failed to do isometric projection");
		ft_free_map(map, map->height);
		exit(EXIT_FAILURE);
	}
	//ft_draw_lines(map);
	ft_draw_points(map);

}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments. Give 1 file, please.\n");
		return (-1);
	}
	else if (!check_if_fdf(argv[1]))
	{
		ft_printf("Error: Wrong file format. The right format: filename.fdf\n");
		return (-1);
	}
	else
		ft_fdf(argv[1]);
	return (0);
}
