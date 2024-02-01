/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:28 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/01 21:36:39 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_string(char *str)
{
	int	word_count;

	word_count = 0;
	if (str == NULL)
		return (put_string("(null)"));
	while (*str != '\0')
	{
		word_count++;
		put_char(*str);
		str++;
	}
	return (word_count);
}

/*
printf

以下の変換を実装しなければならない：
%c：1つの文字を出力します。
%s：文字列を出力します（通常のC規約で定義された方法で）。
%p：void * ポインタ引数を16進数形式で出力します。
%d：10進数（基数10）の数字を出力します。
%i：10進数（基数10）の整数を出力します。
%u：符号なしの10進数（基数10）の数字を出力します。
%x：16進数（基数16）の小文字で数字を出力します。
%X：16進数（基数16）の大文字で数字を出力します。
%%：パーセント記号を出力します。

変換指定子　符号有無　ベース
d あり　10
i
u
x
X　

*/
static void	procexx_d(void)