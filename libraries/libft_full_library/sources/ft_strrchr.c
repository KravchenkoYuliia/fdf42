/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:27 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/22 10:57:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char ** av)
{
	(void)ac;
	printf("%s", ft_strrchr(av[1], *av[2]));
	printf("%s", strrchr(av[1], *av[2]));
}
*/
