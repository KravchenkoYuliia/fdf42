/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:51:49 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 10:00:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = n;
	if (s < d)
	{
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
		return (d);
	}
	else
		return (ft_memcpy(dest, src, n));
}	
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int ac, char **av)
{
	(void)ac;
	printf("ma fonction: %s\n", (char *)ft_memmove(av[1], av[2], atoi(av[3])));
	
    printf("vraie fonction: %s\n", (char *)memmove(av[1], av[2], atoi(av[3])));
	
}
*/
