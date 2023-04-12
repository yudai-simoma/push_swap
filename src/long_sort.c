/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:24:15 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/12 16:39:13 by yshimoma         ###   ########.fr       */
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
void	ft_divide_and_move_b(t_ps_stack *ab_stack, t_long_sort *l_sort)
{
	size_t		i_;

	while (ft_stack_a_size(ab_stack) != 0)
	{
		l_sort->scope_min = 1 + l_sort->scope_max;
		l_sort->scope_max = ((ab_stack->array_size / l_sort->delimiter_num) * 2) + (l_sort->scope_min - 1);
		i_ = 0;
		while (i_ < ab_stack->array_size)
		{
			l_sort->a_top = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
			if (l_sort->a_top >= l_sort->scope_min && l_sort->a_top <= (l_sort->scope_max - (l_sort->delimiter_num / 2)))
				ft_push_b(ab_stack);
			else if (l_sort->a_top >= l_sort->scope_min && l_sort->a_top <= l_sort->scope_max)
			{
				ft_push_b(ab_stack);
				ft_rotate_b(ab_stack);
			}
			else
				ft_rotate_a(ab_stack);
			i_++;
		}
	}
}

void	ft_long_sort(t_ps_stack *ab_stack)
{
	t_long_sort	long_sort_;

	long_sort_.delimiter_num = 6;
	long_sort_.scope_min = 0;
	long_sort_.scope_max = 0;
	ft_stack_print(ab_stack);
	ft_divide_and_move_b(ab_stack, &long_sort_);
	ft_stack_print(ab_stack);
}


	// ft_stack_print(ab_stack);
		// ft_printf("min = %d, max = %d\n", search_scope_min_, search_scope_max_);
		// ft_printf("top = %d\n", a_top_);


//num[b]    = 19,20,15,16,17,14,13,18,11,12,10,7,9,8,5,1,2,4,6,3,
//num[b]    = 19,20,15,16,17,14,13,18,11,12,10,7,9,8,5,4,6,3,2,1,
