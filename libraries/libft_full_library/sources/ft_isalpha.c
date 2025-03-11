/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:40:15 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 18:51:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(int argc, char **argv)
{
	int	i;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		printf("%d ma fonction\n", ft_isalpha(*argv[i]));
		printf("%d la vrai fonction\n", isalpha(*argv[i]));
		i++;
	}
}
*/
