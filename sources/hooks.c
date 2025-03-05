/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/05 12:04:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int	ft_exit(t_mlx* mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_clear_window(mlx->ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win_ptr);
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

void	ft_hooks(t_mlx* mlx)
{
	mlx_hook(mlx->win_ptr, 2, 1L<<0, ft_key_press, (t_mlx*)mlx); //2=KeyPress 1L<<0=KeyPressMask
	mlx_hook(mlx->win_ptr, 17, 1L<<0, ft_exit, (t_mlx*)mlx); //17='x'
}
