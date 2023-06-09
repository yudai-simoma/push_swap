/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:11:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 20:19:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * スタックBへ移動させたグループが、スタックAへ戻ったか判断する関数
 */
static bool	ft_is_search_num(t_ps_stack *ab_stack, t_move *move_a
	, size_t move_section_count)
{
	size_t	i_;
	size_t	ci_;
	int		search_num_min;
	int		search_num_max;

	search_num_max = move_section_count * move_a->section_num;
	search_num_min = search_num_max - (move_a->section_num - 1);
	if (move_a->section_count == move_section_count)
	{
		search_num_max = ab_stack->array_size;
		search_num_min = ab_stack->array_size
			- (ab_stack->array_size % move_a->section_num) + 1;
	}
	ci_ = ab_stack->ab_flg + 1;
	i_ = 0;
	while (i_ < ft_stack_b_size(ab_stack))
	{
		if (ab_stack->cmprsd_arr_rv[ci_] >= search_num_min
			&& ab_stack->cmprsd_arr_rv[ci_] <= search_num_max)
			return (true);
		ci_++;
		i_++;
	}
	return (false);
}

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックAへ戻すとき専用）
 */
static bool	ft_move_a_check(t_ps_stack *ab_stack, int search_num)
{
	size_t	i_;
	size_t	rotate_count_;
	size_t	reverse_rotate_count_;

	i_ = ab_stack->ab_flg + 1;
	rotate_count_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
	{
		rotate_count_++;
		i_++;
	}
	i_ = ab_stack->array_size;
	reverse_rotate_count_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
	{
		reverse_rotate_count_++;
		i_--;
	}
	if (rotate_count_ < reverse_rotate_count_)
		return (true);
	else
		return (false);
}

/*
 * スタックBからAへ戻す関数の続き2
 */
static void	ft_move_a_flg_check(t_ps_stack *ab_stack, t_move *move_a)
{
	size_t	i_;

	if (move_a->a_move_flg == 0)
		ft_push_a(ab_stack);
	else if (move_a->a_move_flg == 1)
	{
		ft_push_a(ab_stack);
		ft_swap_a(ab_stack);
		move_a->a_move_flg = 0;
	}
	else if (move_a->a_move_flg > 1)
	{
		i_ = 0;
		while (i_++ < move_a->a_move_flg)
			ft_rotate_a(ab_stack);
		ft_push_a(ab_stack);
		i_ = 0;
		while (i_++ < move_a->a_move_flg)
			ft_reverse_rotate_a(ab_stack);
		move_a->a_move_flg = 0;
	}
	move_a->search_num = move_a->search_num_more;
	move_a->search_num_more = move_a->search_num - 1;
}

/*
 * スタックBからAへ戻す関数の続き1
 */
static void	ft_move_a_judge(t_ps_stack *ab_stack, t_move *move_a)
{
	move_a->top_num = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1];
	if (move_a->top_num == move_a->search_num)
	{
		ft_move_a_flg_check(ab_stack, move_a);
	}
	else if (move_a->top_num == move_a->search_num_more)
	{
		ft_push_a(ab_stack);
		move_a->a_move_flg++;
		move_a->search_num_more--;
	}
	else
	{
		if (ft_move_a_check(ab_stack, move_a->search_num))
			ft_rotate_b(ab_stack);
		else
			ft_reverse_rotate_b(ab_stack);
	}
}

/*
 * スタックBからAへ戻す関数
 */
void	ft_ascending_move_a(t_ps_stack *ab_stack, t_move *move_a)
{
	size_t	move_section_count_;

	move_section_count_ = move_a->section_count;
	while (ft_stack_b_size(ab_stack) != 0)
	{
		move_a->a_move_flg = 0;
		while (ft_is_search_num(ab_stack, move_a, move_section_count_))
		{
			ft_move_a_judge(ab_stack, move_a);
		}
		move_section_count_--;
	}
}
