/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/22 17:21:09 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_press(int keycode, t_hook *param)
{
	if (keycode == 65307)
	{
		mlx_loop_end(param->mlx->ptr);
	}
	return (0);
}

int	ft_mouse_hook(int button)
{
	if (button == 1)
		ft_printf("You pressed left button on the mouse\n");
	else if (button == 2)
		ft_printf("You pressed middle button on the mouse\n");
	else if (button == 3)
		ft_printf("You pressed right button on the mouse\n");
	else if (button == 4)
		ft_printf("You scrolled up\n");
	else if (button == 5)
		ft_printf("You scrolled down\n");
	return (0);
}

t_hook	*ft_hooks(t_mlx *mlx, t_map *map)
{
	t_hook	*hook;

	hook = malloc(sizeof(t_hook));
	if (!hook)
		return (NULL);
	hook->mlx = mlx;
	hook->map = map;
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &ft_key_press, hook);
	mlx_hook(mlx->win_ptr, 17, 1L << 0, &mlx_loop_end, mlx->ptr);
	mlx_mouse_hook(mlx->win_ptr, &ft_mouse_hook, mlx);
	return (hook);
}
