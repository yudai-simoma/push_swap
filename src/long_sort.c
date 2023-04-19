/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:24:15 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/19 18:47:15 by yshimoma         ###   ########.fr       */
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
static bool	ft_move_b_check(t_ps_stack *ab_stack, int min, int max)
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
 * スタックAからBへ移動させる関数の続き
 */
static void	ft_move_b_judge(t_ps_stack *ab_stack, t_move *move_b)
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
}

/*
 * スタックAからBへ移動させる関数
 */
static void	ft_divide_and_move_b(t_ps_stack *ab_stack, t_move *move_b)
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
			ft_move_b_judge(ab_stack, move_b);
			i_++;
		}
	}
}

/*
 * 並び変える要素数が7個以上の場合のソートアルゴリズム
 */
void	ft_long_sort(t_ps_stack *ab_stack)
{
	t_move	move_;

	if (ab_stack->array_size <= 110)
		move_.section_num = 15;
	else if (ab_stack->array_size <= 510)
		move_.section_num = 32;
	move_.section_count = ab_stack->array_size / move_.section_num;
	if (ab_stack->array_size % move_.section_num != 0)
		move_.section_count++;
	move_.search_num = 0;
	move_.search_num_more = 0;
	ft_divide_and_move_b(ab_stack, &move_);
	move_.search_num = ab_stack->array_size;
	move_.search_num_more = ab_stack->array_size - 1;
	ft_ascending_move_a(ab_stack, &move_);
}

// スタックの中身を確認できる
// ft_stack_print(ab_stack);

/*
-l 500 -c 500

28
---- Result ----
max   : 5576
median: 5367
min   : 5111

29
---- Result ----
max   : 5543
median: 5335
min   : 5114

30
---- Result ----
max   : 5524
median: 5319
min   : 5081

31
---- Result ----
max   : 5552
median: 5329
min   : 5094

32
---- Result ----
max   : 5521
median: 5305
min   : 5091

33
---- Result ----
max   : 5570
median: 5320
min   : 5090

34
---- Result ----
max   : 5537
median: 5314
min   : 5065

35
---- Result ----
max   : 5618
median: 5324
min   : 5041

*/