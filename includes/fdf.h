/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/02/22 18:31:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "mlx_int.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>

//struct for every point of map
typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

typedef	struct	s_map{
	int	width; //numbers in line (columns)
	int	height; //number of lines (rows)
	int**	matrix; //array for stocking z-values (height of each x,y point)
} t_map;

#endif
