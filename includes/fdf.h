/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/02/24 11:39:41 by yukravch         ###   ########.fr       */
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
	int	width; //numbers in line (x-columns)
	int	height; //number of lines (y-rows)
	t_point**	matrix; //2D-array struct for stocking z-values (height and color of each x,y point)
} t_map;

#endif
