/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:08:31 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/13 20:44:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//スタックaの先頭の2つの要素を入れ替える。
//要素が1つしかない場合、または要素がない場合は何もしない。
void	ft_swap_a(t_ps_stack *ab_stack)
{
	if (ft_stack_a_size(ab_stack) <= 1)
		return ;
	ft_swap(&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg],
		&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg - 1]);
	ft_putendl_fd("sa", 1);
}

//スタックbの先頭の2つの要素を入れ替える。
//要素が1つしかない場合、または要素がない場合は何もしない。
void	ft_swap_b(t_ps_stack *ab_stack)
{
	if (ft_stack_b_size(ab_stack) <= 1)
		return ;
	ft_swap(&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 1],
		&ab_stack->cmprsd_arr_rv[ab_stack->ab_flg + 2]);
	ft_putendl_fd("sb", 1);
}

//saとsbを同時に行う
void	ft_swap_ab(t_ps_stack *ab_stack)
{
	ft_swap_a(ab_stack);
	ft_swap_b(ab_stack);
}
