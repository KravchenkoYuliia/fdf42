/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:58 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 14:57:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char ** av)
{
	(void)ac;
	printf("%s", ft_strchr(av[1], *av[2]));
	//printf("%s", strchr(av[1], *av[2]));
}
*/
