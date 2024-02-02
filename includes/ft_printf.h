/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:42:14 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/02 23:22:31 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

char	*ft_itoa(int n);
int	print_d_i(int nbr);
int	print_u(unsigned int nbr);
int	count_strlen(const char *str);
int	print_char(char c);
int	print_string(char *str);

int	ft_printf(const char *format, ...);
#endif