/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:24:19 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/24 14:32:58 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	n;

	i = 0;
	n = '\n';
	if (fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &n, 1);
}
/*
#include <fcntl.h>
int	main()
{
	int	fd = open("test", O_WRONLY);
	ft_putendl_fd("Bonjour", fd);
}
*/
