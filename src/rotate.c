/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:02:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/09 15:23:14 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//スタックaの全要素を1つずつシフトアップする。
// 最初の要素が最後の要素になる。
void	ft_rotate_a(t_ps_stack *ab_stack)
{
	int	top_val;

	if (ft_stack_a_size(ab_stack) <= 1)
		return ;
	top_val = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg];
	ft_memmove(&ab_stack->cmprsd_arr_rv[2], &ab_stack->cmprsd_arr_rv[1],
		(ab_stack->ab_flg - 1) * sizeof(int));
	ab_stack->cmprsd_arr_rv[1] = top_val;
}

//スタックbの全要素を1つずつシフトアップする。
// 最初の要素が最後の要素になる。
void	ft_rotate_b(t_ps_stack *ab_stack)
{
	int	top_val;

	if (ft_stack_b_size(ab_stack) <= 1)
		return ;
	top_val = ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1];
	ft_memmove(&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1],
		&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 2],
		(ab_stack->array_size - ab_stack->ab_flg) * sizeof(int));
	ab_stack->cmprsd_arr_rv[ab_stack->array_size] = top_val;
}

// //raとrbを同時に使用する。
void	ft_rotate_ab(t_ps_stack *ab_stack)
{
	ft_rotate_a(ab_stack);
	ft_rotate_b(ab_stack);
}
