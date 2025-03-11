/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:31:34 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 15:28:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ft_isalpha(ch) || ft_isdigit(ch))
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
		printf("%d ma fonction\n", ft_isalnum(*argv[i]));
		printf("%d la vrai fonction\n", isalnum(*argv[i]));
		i++;
	}
}
*/
