/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:41:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/18 20:12:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 並び変える要素数が3個以下をソートする関数
 * 1, 2, 3の値のみに使用可能
 */
static void	ft_sort_size_3(t_ps_stack *ab_stack)
{
	int	top;
	int	next;

	top = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
	next = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg - 1];
	if (top == 1 && next == 3)
	{
		ft_swap_a(ab_stack);
		ft_rotate_a(ab_stack);
	}
	else if (top == 2 && next == 1)
		ft_swap_a(ab_stack);
	else if (top == 2 && next == 3)
		ft_reverse_rotate_a(ab_stack);
	else if (top == 3 && next == 1)
		ft_rotate_a(ab_stack);
	else if (top == 3 && next == 2)
	{
		ft_swap_a(ab_stack);
		ft_reverse_rotate_a(ab_stack);
	}
}

/*
 * 並び変える要素数が6個以下の場合のソートアルゴリズム
 */
void	ft_min_sort(t_ps_stack *ab_stack)
{
	if (ab_stack->array_size == 2)
		ft_swap_a(ab_stack);
	else if (ab_stack->array_size == 3)
		ft_sort_size_3(ab_stack);
	else
		ft_sort_size_max_6(ab_stack);
}
