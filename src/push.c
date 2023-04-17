/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:50:32 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 18:23:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * bの先頭にある最初の要素を取り出し、aの先頭に置く
 * bが空の場合は何もしない
 */
void	ft_push_a(t_ps_stack *ab_stack)
{
	if (ft_stack_b_size(ab_stack) == 0)
		return ;
	ab_stack->ab_flg++;
	ft_putendl_fd("pa", 1);
}

/*
 * aの先頭にある最初の要素を取り、bの先頭に置く
 * aが空の場合は何もしない
 */
void	ft_push_b(t_ps_stack *ab_stack)
{
	if (ft_stack_a_size(ab_stack) == 0)
		return ;
	ab_stack->ab_flg--;
	ft_putendl_fd("pb", 1);
}
