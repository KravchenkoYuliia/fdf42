/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:16:02 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 14:53:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	j = 0;
	str = (char *)big;
	to_find = (char *)little;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && str[i + j] && (i + j < len))
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
int	main(int ac, char **av)
{
	char *result;
	
	(void)ac;
	result = ft_strnstr(av[1], av[2], atoi(av[3]));
	printf("%s", result);
}
*/
