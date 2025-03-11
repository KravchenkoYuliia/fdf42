/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:36:20 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/24 12:03:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar('0' + n, fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n == -2147483648)
	{
		ft_putchar('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
}
/*
#include <fcntl.h>

int	main()
{
	int	fd = open("test", O_WRONLY);
	ft_putnbr_fd(-2147483648, fd);
}
*/
