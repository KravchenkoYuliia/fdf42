/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:13:39 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 09:28:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;

	if (!dest && !src)
		return (0);
	i = 0;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int ac, char **av)
{
	(void)ac;
	ft_memcpy(av[1], av[2], atoi(av[3]));
	printf("ma fonction: %s\n", av[1]);
	
	
	memcpy(av[1], av[2], atoi(av[3]));
    printf("vraie fonction: %s\n", av[1]);
}
*/
