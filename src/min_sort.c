/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:41:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 21:21:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 並び変える要素数が3個以下をソートする関数
 * 1, 2, 3の値のみに使用可能
 */
void	ft_sort_size_3(t_ps_stack *ab_stack, int *cmprsd_arr_rv)
{
	int	top;
	int	next;

	top = cmprsd_arr_rv[ab_stack->ab_flg];
	next = cmprsd_arr_rv[ab_stack->ab_flg - 1];
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
 * ft_sort_size_3()関数に渡す引数を用意する関数
 */
static void	set_sort_3_num(int *num, int *sort_3_num)
{
	sort_3_num[0] = num[0];
	sort_3_num[1] = num[1];
	sort_3_num[2] = num[2];
	sort_3_num[3] = num[3];
}

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックAへ戻すとき専用）
 */
static bool	ft_rotate_or_reverse_rotate_check(t_ps_stack *ab_stack
	, int search_num)
{
	size_t	i_;
	size_t	rotate_count_;
	size_t	reverse_rotate_count_;

	i_ = ft_stack_a_size(ab_stack);
	rotate_count_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
	{
		rotate_count_++;
		i_--;
	}
	i_ = 1;
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

/*
 * 並び変える要素数が4~6個のソートアルゴリズム
 */
void	ft_sort_size_max_6(t_ps_stack *ab_stack,
	int *cmprsd_arr_rv, int array_size)
{
	int	a_top_;
	int	search_num_;
	int	sort_3_num[4];

	search_num_ = array_size;
	while (search_num_ != 3)
	{
		a_top_ = cmprsd_arr_rv[ab_stack->ab_flg];
		if (a_top_ == search_num_)
		{
			ft_push_b(ab_stack);
			search_num_--;
		}
		else if (ft_rotate_or_reverse_rotate_check(ab_stack, search_num_))
			ft_rotate_a(ab_stack);
		else
			ft_reverse_rotate_a(ab_stack);
	}
	set_sort_3_num(cmprsd_arr_rv, sort_3_num);
	ft_sort_size_3(ab_stack, sort_3_num);
	while (ft_stack_b_size(ab_stack) != 0)
	{
		ft_push_a(ab_stack);
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
		ft_sort_size_3(ab_stack, ab_stack->cmprsd_arr_rv);
	else
		ft_sort_size_max_6(ab_stack, ab_stack->cmprsd_arr_rv,
			ab_stack->array_size);
}
