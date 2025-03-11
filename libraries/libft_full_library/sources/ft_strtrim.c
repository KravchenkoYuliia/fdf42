/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:10:26 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 14:35:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_set(char const *set, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)s1;
	j = ft_strlen(str) - 1;
	while (ft_check_set(set, str[j]))
		j--;
	while (ft_check_set(set, str[i]))
		i++;
	return (ft_substr(str, i, j - i + 1));
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%s", ft_strtrim(av[1], av[2]));
}
*/
