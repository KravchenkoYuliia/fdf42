/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:14:40 by yukravch          #+#    #+#             */
/*   Updated: 2025/03/04 16:54:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     check_if_fdf(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i > 4 && filename[i-1] == 'f' && filename[i-2] == 'd' && filename[i-3] == 'f' && filename[i-4] == '.')
		return (1);
	return (0);
}

int     main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments. Give 1 file, please.\n");
		return (-1);
	}
	else if (!check_if_fdf(argv[1]))
	{	
		ft_printf("Error: Wrong file format. The right format: filename.fdf\n");
		return (-1);
	}
	else
		ft_fdf(argv[1]);
	return (0);
}

