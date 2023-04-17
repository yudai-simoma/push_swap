/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:17:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 18:25:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * スタックaの個数を数える
 */
size_t	ft_stack_a_size(t_ps_stack *ab_stack)
{
	size_t	i_;

	i_ = 0;
	while (i_ < ab_stack->ab_flg)
		i_++;
	return (i_);
}

/*
 * スタックbの個数を数える
 */
size_t	ft_stack_b_size(t_ps_stack *ab_stack)
{
	size_t	i_;
	size_t	a_size;

	i_ = 0;
	a_size = ab_stack->ab_flg;
	while (a_size < ab_stack->array_size)
	{
		a_size++;
		i_++;
	}
	return (i_);
}

/*
 * 第一引数と第二引数の値の入れ替え
 */
void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}
