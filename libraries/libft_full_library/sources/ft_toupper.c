/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:25:09 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 17:46:36 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	letter;

	letter = (unsigned char)c;
	if (letter >= 97 && letter <= 122)
		return (letter -32);
	return (c);
}
/*
#include <stdio.h>
int	main (int ac, char **av)
{
	(void)ac;
	printf("%c", ft_toupper((char)*av[1]));
}
*/
