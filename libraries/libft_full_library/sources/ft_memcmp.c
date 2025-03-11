/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:56:59 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 16:24:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	int	result;
	result = ft_memcmp(av[1], av[2], atoi(av[3]));
	if(result > 0) {
      printf("str2 is less than str1");
   } 
   else if(result < 0) {
      printf("str1 is less than str2");
   } 
   else {
      printf("str1 is equal to str2");
   }
   return(0);
}
*/
