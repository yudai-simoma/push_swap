/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:24:15 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/13 20:46:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// ・要素数 / 15で区切る
	// ・(区切った個数 / 2) - 1 回分スタックAをrotateし比較する
	// ・rotateする際、1回目は1 ~ 30の値を見る、1~15ならpush,rotate、16~30ならpush
	// 	2回目は、31 ~ 45ならpush,rotate、46 ~ 60ならpushとしスタックBに15の範囲で
	// 	区切った値を格納していく
	// ・スタックAのrotateが終了したら、スタックBをrotate,revase_rotateをし比較する
	// ・スタックBを比較する際は、スタックBに格納されている最大値を見つけ、
	// 	見つけたらスタックAにpushm,フラグが0になるまでrevase=rotate
	// 	、最大値 - 1を見つけたらスタックAにpush,rotate,フラグを1++
	// ・上記をスタックBが空になるまで実行する
	// ・

/*
	8個に区切る
	1~8を探す
*/

/*
 * 一定数で分割しながら並び替えを行いスタックBへ移動させる
 * (ab_stack->array_size / l_sort->delimiter_num) * 2) + (l_sort->scope_min - 1)
 * ((配列の要素数 / 分割する基準値) * 2) + (分割する最小値 - 1))
 */
void	ft_divide_and_move_b(t_ps_stack *ab_stack, t_move_b *move_b)
{
	size_t	i_;
	int		a_top;

	while (ft_stack_a_size(ab_stack) != 0)
	{
		move_b->scope_min = 1 + move_b->scope_max;
		move_b->scope_max = move_b->delimiter_num + (move_b->scope_min - 1);
		i_ = 0;
		while (i_ < ab_stack->array_size)
		{
			a_top = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
			if (a_top >= move_b->scope_min
				&& a_top <= (move_b->scope_max - (move_b->delimiter_num / 2)))
				ft_push_b(ab_stack);
			else if (a_top >= move_b->scope_min && a_top <= move_b->scope_max)
			{
				ft_push_b(ab_stack);
				ft_rotate_b(ab_stack);
			}
			else
				ft_rotate_a(ab_stack);
			i_++;
		}
		// ft_stack_print(ab_stack);
	}
}

bool	ft_rotate_or_reverse_rotate_check(t_ps_stack *ab_stack, int top_b)
{
	size_t	find_rotate_;
	size_t	fine_reverse_rotate_;
	size_t	i_;

	i_ = 1;
	while (ab_stack->cmprsd_arr_rv[i_] != top_b)
		i_++;
	find_rotate_ = i_;
	i_ = ab_stack->array_size;
	while (ab_stack->cmprsd_arr_rv[i_] != top_b)
		i_--;
	fine_reverse_rotate_ = i_;
	if (find_rotate_ < fine_reverse_rotate_)
		return (true);
	else
		return (false);
}

//スタックBからスタックAへ移動させる関数
/*
 * 検索値が来たら、flgを確認し、flg=0ならpush、flg=1ならpush,swap、flg<1ならflg回分rotate,push,flg回分reverse_rotate
 * 検索値の1つ前が来たら、push,flg++
 * さらに1つ前の値が来たらpush,flg++
 */
void	ft_ascending_move_a(t_ps_stack *ab_stack, t_move_b *move_b)
{
	size_t		i_;
	t_move_a	move_a_;

	move_a_.search_num = ab_stack->array_size;
	move_a_.search_num_next = move_a_.search_num - 1;
	move_a_.group_move_count = 0;
	move_a_.search_num_flg = ab_stack->array_size % move_b->delimiter_num;
	while (ft_stack_b_size(ab_stack) != 0)
	{
		move_a_.a_move_flg = 0;
		if (move_a_.group_move_count != 0)
			move_a_.search_num_flg = move_b->delimiter_num / 2;
		while (move_a_.search_num_flg != 0)
		{
			move_a_.b_top_ = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1];
			if (move_a_.b_top_ == move_a_.search_num)
			{
				if (move_a_.a_move_flg == 0)
					ft_push_a(ab_stack);
				else if (move_a_.a_move_flg == 1)
				{
					ft_push_a(ab_stack);
					ft_swap_a(ab_stack);
				}
				else if (move_a_.a_move_flg > 1)
				{
					i_ = 0;
					while (i_++ < move_a_.a_move_flg)
						ft_rotate_a(ab_stack);
					ft_push_a(ab_stack);
					i_ = 0;
					while (i_++ < move_a_.a_move_flg)
						ft_reverse_rotate_a(ab_stack);
					move_a_.a_move_flg = 0;
				}
				move_a_.search_num--;
				move_a_.search_num_next = move_a_.search_num - 1;
				move_a_.search_num_flg--;
			}
			else if (move_a_.b_top_ == move_a_.search_num_next)
			{
				ft_push_a(ab_stack);
				move_a_.a_move_flg++;
				move_a_.search_num_next--;
				move_a_.search_num_flg--;
			}
			else
			{
				if (ft_rotate_or_reverse_rotate_check(ab_stack, move_a_.b_top_))
					ft_rotate_b(ab_stack);
				else
					ft_reverse_rotate_b(ab_stack);
			}
		}
		move_a_.group_move_count++;
	}
}

void	ft_long_sort(t_ps_stack *ab_stack)
{
	t_move_b	move_b_;

	move_b_.delimiter_num = 6;
	move_b_.scope_min = 0;
	move_b_.scope_max = 0;
	// ft_printf("before_move_b\n");
	// ft_stack_print(ab_stack);
	ft_divide_and_move_b(ab_stack, &move_b_);
	// ft_printf("after_move_b\n");
	// ft_stack_print(ab_stack);
	// ft_printf("before_move_a\n");
	// ft_stack_print(ab_stack);
	ft_ascending_move_a(ab_stack, &move_b_);
	// ft_printf("after_move_a\n");
	// ft_stack_print(ab_stack);
}


	// ft_stack_print(ab_stack);
		// ft_printf("min = %d, max = %d\n", search_scope_min_, search_scope_max_);
		// ft_printf("top = %d\n", a_top_);


//num[b]    = 19,20,15,16,17,14,13,18,11,12,10,7,9,8,5,1,2,4,6,3,
//num[b]    = 19,20,15,16,17,14,13,18,11,12,10,7,9,8,5,4,6,3,2,1,
