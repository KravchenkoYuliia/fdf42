/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/11 14:53:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_exit(t_mlx* mlx)
{
	if (mlx->ptr && mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->ptr && mlx->win_ptr)
	{	mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	}
	if (mlx->ptr)
		mlx_destroy_display(mlx->ptr);
	exit(0);
	return (0);
}

int	ft_key_press(int keycode, t_mlx* mlx)
{
	/*ft_printf("%d", keycode);
	 * 65307 = esc
	 * 65362 = up
	 * 65364 = down
	 * 65363 = >
	 * 65361 = <
	 */

	if (keycode == 65307)
	{
		ft_exit(mlx);
	}
	return (0);
}

int	ft_mouse_hook(int button)
{
//	ft_printf("%d", button);
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

void	ft_hooks(t_mlx* mlx, t_map* map)
{
	(void)map;
	mlx_hook(mlx->win_ptr, 2, 1L<<0, ft_key_press, mlx); //2=KeyPress 1L<<0=KeyPressMask
	mlx_hook(mlx->win_ptr, 17, 1L<<0, ft_exit, mlx); //17='x'
	//mlx_expose_hook(mlx->win_ptr, ft_hz, (t_mlx*)mlx);
	mlx_mouse_hook(mlx->win_ptr, ft_mouse_hook, mlx);
}
