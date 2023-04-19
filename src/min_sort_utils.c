/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:59:51 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/19 18:57:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックAへ戻すとき専用）
 */
static bool	ft_rotate_or_reverse_rotate_check(t_ps_stack *ab_stack
	, int search_num)
{
	size_t	i_;
	size_t	rotate_count_;
	size_t	reverse_rotate_count_;

	i_ = ab_stack->ab_flg;
	rotate_count_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
	{
		rotate_count_++;
		i_--;
	}
	i_ = 0;
	reverse_rotate_count_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
	{
		reverse_rotate_count_++;
		i_++;
	}
	if (rotate_count_ < reverse_rotate_count_)
		return (true);
	else
		return (false);
}

static void	ft_sort_3_size(t_ps_stack *ab_stack)
{
	int	top;
	int	next;

	top = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
	next = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg - 1];
	if (top == 4 && next == 6)
	{
		ft_swap_a(ab_stack);
		ft_rotate_a(ab_stack);
	}
	else if (top == 5 && next == 4)
		ft_swap_a(ab_stack);
	else if (top == 5 && next == 6)
		ft_reverse_rotate_a(ab_stack);
	else if (top == 6 && next == 4)
		ft_rotate_a(ab_stack);
	else if (top == 6 && next == 5)
	{
		ft_swap_a(ab_stack);
		ft_reverse_rotate_a(ab_stack);
	}
}

/*
 * スタックAに残した4~6の値をソートする関数
 */
static void	ft_sort_4_to_6(t_ps_stack *ab_stack)
{
	if (ft_stack_a_size(ab_stack) == 1)
		return ;
	else if (ft_stack_a_size(ab_stack) == 2)
	{
		if (ab_stack->cmprsd_arr_rv[ab_stack->ab_flg] == 5)
			ft_swap_a(ab_stack);
	}
	else if (ft_stack_a_size(ab_stack) == 3)
		ft_sort_3_size(ab_stack);
}

/*
 * 並び変える要素数が4~6個のソートアルゴリズム
 */
void	ft_sort_size_max_6(t_ps_stack *ab_stack)
{
	int	a_top_;
	int	search_num_;

	search_num_ = 1;
	while (search_num_ < 4)
	{
		a_top_ = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
		if (a_top_ == search_num_)
		{
			ft_push_b(ab_stack);
			search_num_++;
		}
		else if (ft_rotate_or_reverse_rotate_check(ab_stack, search_num_))
			ft_rotate_a(ab_stack);
		else
			ft_reverse_rotate_a(ab_stack);
	}
	ft_sort_4_to_6(ab_stack);
	while (ft_stack_b_size(ab_stack) != 0)
		ft_push_a(ab_stack);
}
