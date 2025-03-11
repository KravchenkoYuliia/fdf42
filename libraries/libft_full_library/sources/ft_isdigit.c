/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:11:38 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 15:30:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
		printf("%d ma fonction\n", ft_isdigit(*argv[i]));
		printf("%d la vrai fonction\n", isdigit(*argv[i]));
		i++;
	}
}
*/
