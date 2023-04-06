/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:06:31 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/30 18:52:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 数値が何桁か判断する関数
 */
static size_t	ft_malloc_size(size_t n)
{
	size_t	malloc_size;

	malloc_size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		malloc_size++;
	}
	return (malloc_size);
}

/*
 * 数値を文字列に格納する
 */
static char	*ft_set_itoa(char *return_str, size_t n, size_t size)
{
	while (size > 0)
	{
		return_str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (return_str);
}

/*
 * unsigned intの数値を文字列にして返す関数
 */
char	*ft_size_t_itoa(size_t n)
{
	char	*return_str;
	size_t	malloc_size;

	malloc_size = ft_malloc_size(n);
	return_str = (char *)ft_calloc_p(malloc_size + 1, sizeof(char));
	if (return_str == NULL)
		return (NULL);
	return_str = ft_set_itoa(return_str, n, malloc_size);
	return (return_str);
}

/*
 * %u の場合に呼ばれる
 * size_tを文字列にした値の出力と、出力した文字列の長さを格納する
 */
void	put_size_t_nbr(size_t a_nbr, size_t *a_return_num)
{
	char	*r_str;

	r_str = ft_size_t_itoa(a_nbr);
	if (r_str == NULL)
		r_str = "";
	ft_putstr_fd_p(r_str, 1);
	(*a_return_num) += ft_strlen_p(r_str);
	free(r_str);
	r_str = NULL;
}
