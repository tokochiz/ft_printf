/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:28 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/02 18:15:23 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	print_char(char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
	return (1);
}

int	print_string(char *str)
{
	int	len;

	if (str == NULL)
	{
		len = write(1, "(null)", 6);
	}
	else
	{
		len = count_strlen(str);
		write(1, str, len);
	}
	return (len);
}

// int	print_nbr(int)
// {

// }