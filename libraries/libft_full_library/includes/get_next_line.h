/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:59:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/02/17 12:36:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*ft_cut_line(char *reserve);
char	*ft_copy_from_buffer(char *reserve, char *buffer);
char	*ft_get_line(char *full_reserve);
char	*ft_read_buffer(int fd, char *reserve);
char	*get_next_line(int fd);
char	*ft_strcpy_gnl(char *dest, char *src);
int	ft_strchr_gnl(const char *s, int c);

#endif
