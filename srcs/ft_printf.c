/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:51:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/02 19:31:01 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_hex(unsigned long long input_nbr, int lower_case)
{
	char	*hex_type;
	char	*hex_digits;
	int		index;

	// if (input_nbr == 0)
	// 	return (print_char('0'));
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
	printf("\n**88");
	printf("\n88++++%s", hex_digits);
	return (hex_digits);
}

static int	print_pointer(void *ptr)
{
	char	*ptr_digits;
	int		word_count;

	uintptr_t uintptr_ptr; //ポインタを表現できる符号なし整数型
	uintptr_ptr = (uintptr_t)ptr;
	ptr_digits = convert_hex(uintptr_ptr, 1);
	if (ptr_digits == NULL)
		return (0);
	word_count = count_strlen(ptr_digits);
	write(1, ptr_digits, word_count);
	free(ptr_digits);
	return (word_count);
}

// static int	print_hex_digits(unsigned long long input_nbr, int lower_cace)
// {
// 	char	*hex_digits;
// 	int		word_count;
	
// 	printf("+++%llu", input_nbr);
// 	hex_digits = convert_hex(input_nbr, lower_cace);
	
// 	printf("\n++++%s", hex_digits);
// 	if (hex_digits == NULL)
// 		return (0);
// 	word_count = count_strlen(hex_digits);
// 	write(1, hex_digits, word_count);
// 	free(hex_digits);
// 	return (word_count);
// }

static int	process_dispatch(va_list arguments, char specifier)
{
	if (specifier == '%')
		return (print_char('%'));
	else if (specifier == 'c')
		return (print_char(va_arg(arguments, int)));
	else if (specifier == 's')
		return (print_string(va_arg(arguments, char *)));
	// TODO : %iが符号つき(1)の整数として解釈される際、符号プレフィックス（+ または -） +の時も＋って付ける
	else if (specifier == 'd' || specifier == 'i')
		return (print_decimal(va_arg(arguments, int)));
	// TODO : %u：符号なし(0)の10進数（基数10）の数字を出力
	else if (specifier == 'x')
		return (print_hex_digits(va_arg(arguments, unsigned long long), 1));

	else if (specifier == 'X')
		return (print_hex_digits(va_arg(arguments, unsigned long long), 0));

	else if (specifier == 'p')
		return (print_pointer(va_arg(arguments, void *)));
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

int	main(void)
{
	char	test_c = '1';
	char *test_s ="abcde";
	int test_d = 214748364;
	int test_i = -2147483648;
	int test_x = 1967;// (7af)16 
	
	printf("printf    :%c\n", test_c);
	ft_printf("ft_printf :%c\n", test_c);
	printf("----------------------\n");
	printf("printf    :%s\n", test_s);
	ft_printf("ft_printf :%s\n", test_s);
		printf("----------------------\n");
	printf("printf    :%d\n", test_d);
	ft_printf("ft_printf :%d\n", test_d);
			printf("----------------------\n");
	printf("printf    :%i\n", test_i);
	ft_printf("ft_printf :%i\n", test_i);
	printf("----------------------\n");
	printf("printf    :%x|\n", test_x);
	ft_printf("ft_printf :%x|\n", test_x);
}
