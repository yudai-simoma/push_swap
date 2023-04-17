/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:24:15 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 18:27:19 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * 7個以上のソートアルゴリズム
 * （例：要素数10個、区切る数3の場合。区切る数は要素数によって変動する）
 * 	・スタックAが空になるまでスタックBにグループごとに移動させる
 * 		・「7~9, 1~3, 4~6, 10」のように3個のグループにし、大小のグループを交互にさせる
 * 	・スタックBが空になるまでスタックAに大きい順に戻す
 * 		・一番初めは、10, 9 を探し10を見つけたら次は、9, 8を探す
 * 		・仮に10, 9 を探し、9を見つけたら次は、10, 8を探す
 * 	・スタックAに戻したら、ソートが完了している
 */

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックBへ移動させるとき専用）
 */
bool	ft_move_b_check(t_ps_stack *ab_stack, int min, int max)
{
	size_t	i_;
	size_t	rotate_count_;
	size_t	reverse_rotate_count_;

	i_ = 0;
	while (ab_stack->cmprsd_arr_rv[i_] >= min
		&& ab_stack->cmprsd_arr_rv[i_] <= max)
		i_++;
	rotate_count_ = i_;
	i_ = ft_stack_a_size(ab_stack);
	while (ab_stack->cmprsd_arr_rv[i_] >= min
		&& ab_stack->cmprsd_arr_rv[i_] <= max)
		i_--;
	reverse_rotate_count_ = i_;
	if (rotate_count_ < reverse_rotate_count_)
		return (true);
	else
		return (false);
}

/*
 * スタックAからBへ移動させる関数
 */
void	ft_divide_and_move_b(t_ps_stack *ab_stack, t_move *move_b)
{
	size_t	i_;
	size_t	stack_a_size;

	while (ft_stack_a_size(ab_stack) != 0)
	{
		move_b->search_num = 1 + move_b->search_num_more;
		move_b->search_num_more = (move_b->section_num * 2)
			+ (move_b->search_num - 1);
		i_ = 0;
		stack_a_size = ft_stack_a_size(ab_stack);
		while (i_ < stack_a_size)
		{
			move_b->top_num = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
			if (move_b->top_num >= move_b->search_num && move_b->top_num
				<= move_b->search_num_more - move_b->section_num)
				ft_push_b(ab_stack);
			else if (move_b->top_num >= move_b->search_num
				&& move_b->top_num <= move_b->search_num_more)
			{
				ft_push_b(ab_stack);
				ft_rotate_b(ab_stack);
			}
			else
			{
				if (ft_move_b_check(ab_stack,
						move_b->search_num, move_b->search_num_more))
					ft_rotate_a(ab_stack);
				else
					ft_reverse_rotate_a(ab_stack);
			}
			i_++;
		}
		// ft_stack_print(ab_stack);
	}
}

/*
 * スタックBへ移動させたグループが、スタックAへ戻ったか判断する関数
 */
bool	ft_is_search_num(t_ps_stack *ab_stack, t_move *move_a
	, size_t move_section_count)
{
	int	i_;
	int	search_num_min;
	int	search_num_max;

	if (move_a->section_count == move_section_count)
	{
		search_num_max = ab_stack->array_size;
		search_num_min = ab_stack->array_size
			- (ab_stack->array_size % move_a->section_num) + 1;
	}
	else
	{
		search_num_max = move_a->section_count * move_a->section_num;
		search_num_min = search_num_max - move_a->section_num + 1;
	}
	i_ = ab_stack->ab_flg + 1;
	while (i_)
	{
		if (ab_stack->cmprsd_arr_rv[i_] >= search_num_min
			&& ab_stack->cmprsd_arr_rv[i_] <= search_num_max)
			return (true);
		i_--;
	}
	return (false);
}

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックAへ戻すとき専用）
 */
bool	ft_move_a_check(t_ps_stack *ab_stack, int search_num)
{
	size_t	i_;
	size_t	rotate_count_;
	size_t	reverse_rotate_count_;

	i_ = ab_stack->ab_flg + 1;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
		i_++;
	rotate_count_ = i_;
	i_ = ab_stack->array_size;
	while (ab_stack->cmprsd_arr_rv[i_] != search_num)
		i_--;
	reverse_rotate_count_ = i_;
	if (rotate_count_ < reverse_rotate_count_)
		return (true);
	else
		return (false);
}

//TODO:無限ループに入ってる
/*
 * スタックをBからAへ戻す関数
 */
void	ft_ascending_move_a(t_ps_stack *ab_stack, t_move *move_a)
{
	size_t	move_section_count_;
	size_t	i_;

	move_section_count_ = move_a->section_count;
	while (ft_stack_b_size(ab_stack) != 0)
	{
		move_a->a_move_flg = 0;
		while (ft_is_search_num(ab_stack, move_a, move_section_count_))
		{
			move_a->top_num = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1];
			if (move_a->top_num == move_a->search_num)
			{
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
	}
}

/*
 * 並び変える要素数が7個以上の場合のソートアルゴリズム
 */
void	ft_long_sort(t_ps_stack *ab_stack)
{
	t_move	move_;

	move_.section_num = 3;
	move_.section_count = ab_stack->array_size / move_.section_num;
	if (ab_stack->array_size % move_.section_num != 0)
		move_.section_count++;
	move_.search_num = 0;
	move_.search_num_more = 0;
	// move_.search_num_flg = ab_stack->array_size % move_b->delimiter_num;


	// ft_stack_print(ab_stack);
	ft_divide_and_move_b(ab_stack, &move_);
	// ft_stack_print(ab_stack);
	move_.search_num = ab_stack->array_size;
	move_.search_num_more = ab_stack->array_size - 1;
	ft_ascending_move_a(ab_stack, &move_);

	// ft_printf("after_move_a\n");
	// ft_stack_print(ab_stack);
}


// ft_stack_print(ab_stack);
