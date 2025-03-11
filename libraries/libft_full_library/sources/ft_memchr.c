/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:17:32 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 11:54:20 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (i < n - 1)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int	ac, char **av)
{
	(void)ac;
	char *result;
	result = (char *)ft_memchr((char *)av[1], atoi(av[2]), atoi(av[3]));
	//result = (char *)memchr((char *)av[1], atoi(av[2]), atoi(av[3]));
	//printf("%p\n", &result);
	//printf("%lu\n", sizeof(char));
	//printf("%p", &result + 1);
}
*/
