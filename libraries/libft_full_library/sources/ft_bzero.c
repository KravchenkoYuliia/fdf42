/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:27:00 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 15:25:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	(void)argc;
	ft_bzero(argv[1], 3);
	printf("%s ma fonction\n", argv[1]);
	bzero(argv[1], 3);
	printf("%s la vrai fonction\n", argv[1]);

}
*/
