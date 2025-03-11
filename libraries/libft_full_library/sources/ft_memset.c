/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:19:50 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 17:08:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			src;
	unsigned char	*dest;
	size_t			i;

	src = (char)c;
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = src;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	int	i;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		ft_memset(argv[i] + 5, ',', 1);
		printf("%s ma fonction\n", argv[i]);
		memset(argv[i] + 5, ',', 1);
		printf("%s la vrai fonction\n", argv[i]);
		i++;
	}
}
*/
