/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:24:12 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/13 20:45:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックaの全要素を1つずつシフトダウンする。
// 最後の要素が最初の要素になる。
void	ft_reverse_rotate_a(t_ps_stack *ab_stack)
{
	int	tail_val;

	if (ft_stack_a_size(ab_stack) <= 1)
		return ;
	tail_val = ab_stack->cmprsd_arr_rv[1];
	ft_memmove(&ab_stack->cmprsd_arr_rv[1],
		&ab_stack->cmprsd_arr_rv[2],
		(ab_stack->ab_flg - 1) * sizeof(int));
	ab_stack->cmprsd_arr_rv[ab_stack->ab_flg] = tail_val;
	ft_putendl_fd("rra", 1);
}

// スタックbの全要素を1つずつシフトダウンする。
// 最後の要素が最初の要素になる。
void	ft_reverse_rotate_b(t_ps_stack *ab_stack)
{
	int	tail_val;

	if (ft_stack_b_size(ab_stack) <= 1)
		return ;
	tail_val = ab_stack->cmprsd_arr_rv[ab_stack->array_size];
	ft_memmove(&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 2],
		&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1],
		(ab_stack->array_size - ab_stack->ab_flg - 1) * sizeof(int));
	ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1] = tail_val;
	ft_putendl_fd("rrb", 1);
}

// rraとrrbを同時に使用します。
void	ft_reverse_rotate_ab(t_ps_stack *ab_stack)
{
	ft_reverse_rotate_a(ab_stack);
	ft_reverse_rotate_b(ab_stack);
}
