/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:51:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/01 21:45:57 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(unsigned int input_num, int lower_case)
{
	char	*hex_type;
	char	*hex_digits;
	int		index;
	int		word_count;

	if (input_num == 0)
		return (put_char('0'));
	if (lower_case)
		hex_type = "0123456789abcdef";
	else
		hex_type = "0123456789ABCDEF";
	hex_digits = (char *)malloc(9);
	if (hex_digits == NULL)
		return (0);
	index = 7;
	word_count = 0;
	while (input_num > 0 && index >= 0)
	{
		// TODO: 16で割った数のインデックスと一致する１６進数の文字タイプを出力する
		hex_digits[index] = hex_type[input_num % 16];
		input_num /= 16;
		index--;
	}
	hex_digits[8] = '\0';
	word_count = put_string(hex_digits);
	return (word_count);
}

sitatic int	process_dispatch(va_list arguments, char specifier)
{
	if (specifier == 'c')
		return (put_char(va_arg(arguments, int)));
	else if (specifier == 's')
		return (put_string(va_arg(arguments, char *)));
	// TODO : ポインタ引数を16進数形式で出力
	else if (specifier == 'p')
		return ();
	// TODO : %iが符号つき(1)の整数として解釈される際、符号プレフィックス（+ または -） +の時も＋って付ける
	else if (specifier == 'd' || specifier == 'i')
		return (put_decimal(va_arg(arguments, unsigned int), 1));
	// TODO : %u：符号なし(0)の10進数（基数10）の数字を出力
	else if (specifier == 'u')
		return (put_decimal(va_arg(arguments, unsigned int), 0));
	// TODO : %x：16進数（基数16）の小文字(0)で数字を出力  lower
	else if (specifier == 'x')
		return (convert_hex(va_arg(arguments, unsigned int), 1));
	// TODO : %X：16進数（基数16）の大文字(1)で数字を出力 upper
	else if (specifier == 'X')
		return (convert_hex(va_arg(arguments, unsigned int), 0));
	else if (specifier == '%')
		return (put_char('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		output_count;
	int		i;

	output_count = 0;
	// 引数の初期化 formatより後ろの全引数をリストに格納する
	va_start(arguments, format);
	i = 0;
	// TODO: 文字を受け付け続ける　
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			// TODO: そのあとのの文字の判定をする　→関数を分ける
			i++;
			output_count += process_dispatch(format[i], arguments);
		}
		// TODO: それ以外だったら文字出力
		else
		{
			output_count += 1;
			write(1, &format[i], 1);
		}
		i++;
	}
	// リストをクリアする
	va_end(arguments);
	return (output_count);
}
