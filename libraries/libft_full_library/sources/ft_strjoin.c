/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:42:03 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 17:27:45 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*array;
	int				i;
	int				j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	array = malloc(sizeof(char) * len + 1);
	if (!array)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	return (array);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s", ft_strjoin(av[1], av[2]));	
}
*/
