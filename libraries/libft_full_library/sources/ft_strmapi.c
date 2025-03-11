/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:42:07 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/20 17:34:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*array;

	array = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (s[i])
	{
		array[i] = (*f)(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
char    example(unsigned int index, char l)
  {   
      (void) index;
      return l + 1;
      //return l + index;
  }

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s -> %s\n", argv[1], ft_strmapi(argv[1], &example));
	return 0;
}
*/
