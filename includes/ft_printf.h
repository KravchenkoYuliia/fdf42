/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:35:19 by yukravch          #+#    #+#             */
/*   Updated: 2024/11/28 18:16:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_putchar(int c);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(long nb);
int		ft_print_hexa(unsigned long d, int c);
int		ft_count_hexa(unsigned long d);
int		ft_charset(char mand_arg, char *charset);
int		ft_printf(const char *mand_arg, ...);
void	ft_convert_hexa(unsigned long d, char *base);
int		ft_convert_pointer(void *p);
size_t	ft_put_u_nbr(unsigned int nb);

#endif
