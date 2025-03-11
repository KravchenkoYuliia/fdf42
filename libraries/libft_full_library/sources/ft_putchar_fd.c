/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:06:03 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/24 14:39:53 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
int	main(int ac, char **av)
{
	(void)ac;
	int	fd = open("test", O_WRONLY);
	ft_putchar_fd(*av[1], fd);
	return (0);
}
*/
