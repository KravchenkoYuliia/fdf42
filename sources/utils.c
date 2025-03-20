/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:39:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/20 13:44:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_map *map, int allocated_rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->matrix)
	{
		while (i < allocated_rows)
		{
			if (map->matrix[i])
				free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	free(map);
}

void	*ft_free_2d_array(char **array)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (array[word])
		word++;
	while (i < word)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
