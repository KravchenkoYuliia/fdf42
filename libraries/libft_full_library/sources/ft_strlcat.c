/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:15:06 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 19:32:08 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (d_len < siz)
	{
		while (src[i] && d_len + i < siz - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = '\0';
		return (d_len + s_len);
	}
	return (siz + s_len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("ma fonction: %zu\n", ft_strlcat(av[1], av[2], atoi(av[3])));
	printf("vrai fonction: %zu", strlcat(av[1], av[2], atoi(av[3])));
}
*/
