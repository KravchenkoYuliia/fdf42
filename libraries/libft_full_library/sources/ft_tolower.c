/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:38:56 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 17:45:45 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	letter;

	letter = (unsigned char)c;
	if (letter >= 65 && letter <= 90)
		return (letter + 32);
	return (c);
}
/*
#include <stdio.h>
int	main (int ac, char **av)
{
	(void)ac;
	printf("%c", ft_tolower((char)*av[1]));
}
*/
