/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:51:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/02 23:23:02 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	convert_hex(unsigned long long input_nbr, int lower_case)
{
	char	*hex_type;
	char	*hex_digits;
	int		index;
	int		len;

	if (input_nbr == 0)
		return (print_char('0'));
	if (lower_case)
		hex_type = "0123456789abcdef";
	else
		hex_type = "0123456789ABCDEF";
	hex_digits = (char *)malloc(9);
	if (hex_digits == NULL)
		return (0);
	index = 7;
	while (input_nbr > 0 && index >= 0)
	{
		hex_digits[index] = hex_type[input_nbr % 16];
		input_nbr /= 16;
		index--;
	}
	hex_digits[8] = '\0';
	len = print_string(&hex_digits[index + 1]);
	free(hex_digits);
	return (len);
}

static int	convert_pointer(void *ptr)
{
	uintptr_t u_ptr; //ポインタを表現できる符号なし整数型
	u_ptr = (uintptr_t)ptr;
	return (convert_hex(u_ptr, 1));
}

static int	process_dispatch(va_list arguments, char specifier)
{
	if (specifier == '%')
		return (print_char('%'));
	else if (specifier == 'c')
		return (print_char(va_arg(arguments, int)));
	else if (specifier == 's')
		return (print_string(va_arg(arguments, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_d_i(va_arg(arguments, int)));
	else if (specifier == 'u')
		return (print_u(va_arg(arguments, unsigned int)));
	else if (specifier == 'x')
		return (convert_hex(va_arg(arguments, unsigned long long), 1));
	else if (specifier == 'X')
		return (convert_hex(va_arg(arguments, unsigned long long), 0));
	else if (specifier == 'p')
		return (convert_pointer(va_arg(arguments, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		word_count;
	int		i;

	word_count = 0;
	// 引数の初期化 formatより後ろの全引数をリストに格納する
	va_start(arguments, format);
	i = 0;
	// TODO: 文字を受け付け続ける　
	while (format[i])
	{
		if (format[i] == '%')
		{
			// TODO: そのあとのの文字の判定をする　→関数を分ける
			i++;
			word_count += process_dispatch(arguments, format[i]);
		}
		// TODO: それ以外だったら文字出力
		else
		{
			word_count += 1;
			write(1, &format[i], 1);
		}
		i++;
	}
	// リストをクリアする
	va_end(arguments);
	return (word_count);
}

// int	main(void)
// {
// 	char		test_c;
// 	char		*test_s;
// 	int			test_d;
// 	int			test_i;
// 	int			test_u;
// 	int			test_xX;
// 	uintptr_t	test_p;
// 	int			p_len;

// 	test_c = '1';
// 	test_s = "abcde";
// 	test_d = -2147483648;
// 	test_i = -2147483648;
// 	test_u = -12345;
// 	test_xX = 1967; // (7af)16
	
// 	printf("printf    :%c\n", test_c);
// 	ft_printf("ft_printf :%c\n", test_c);
// 	printf("----------------------------------\n");
// 	printf("printf    :%s\n", test_s);
// 	ft_printf("ft_printf :%s\n", test_s);
// 	printf("----------------------------------\n");
// 	printf("printf    :%d\n", test_d);
// 	ft_printf("ft_printf :%d\n", test_d);
// 	printf("----------------------------------\n");
// 	printf("printf    :%i\n", test_i);
// 	ft_printf("ft_printf :%i\n", test_i);
// 	printf("----------------------------------\n");
// 	printf("printf    :%u\n", test_u);
// 	ft_printf("ft_printf :%u\n", test_u);
// 	printf("----------------------------------\n");
// 	printf("printf    :%x\n", test_xX);
// 	ft_printf("ft_printf :%x\n", test_xX);
// 	printf("----------------------------------\n");
// 	printf("printf    :%X\n", test_xX);
// 	ft_printf("ft_printf :%X\n", test_xX);
// 	printf("----------------------------------\n");
// 	p_len = 0;
// 	p_len = printf("printf    :%p\n", &test_p);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%p\n", &test_p);
// 	printf("ft p_len:%d\n", p_len);
// }
