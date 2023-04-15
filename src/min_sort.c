/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:41:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/15 20:14:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_sort_size_3()関数に渡す引数を用意する関数
void	set_sort_3_num(int *num, int *sort_3_num)
{
	sort_3_num[0] = num[0];
	sort_3_num[1] = num[1];
	sort_3_num[2] = num[2];
	sort_3_num[3] = num[3];
}

//引数が3個以下をソートする関数
void	ft_sort_size_3(t_ps_stack *ab_stack, int *cmprsd_arr_rv)
{
	if (cmprsd_arr_rv[1] == 1 && cmprsd_arr_rv[2] == 3)
	{
		ft_swap_a(ab_stack);
		ft_rotate_a(ab_stack);
	}
	else if (cmprsd_arr_rv[1] == 2 && cmprsd_arr_rv[2] == 1)
		ft_swap_a(ab_stack);
	else if (cmprsd_arr_rv[1] == 2 && cmprsd_arr_rv[2] == 3)
		ft_reverse_rotate_a(ab_stack);
	else if (cmprsd_arr_rv[1] == 3 && cmprsd_arr_rv[2] == 1)
		ft_rotate_a(ab_stack);
	else if (cmprsd_arr_rv[1] == 3 && cmprsd_arr_rv[2] == 2)
	{
		ft_swap_a(ab_stack);
		ft_reverse_rotate_a(ab_stack);
	}
}

//int *の要素数が6個以下のソートアルゴリズム
void	ft_sort_size_max_6(t_ps_stack *ab_stack,
	int *cmprsd_arr_rv, int array_size)
{
	int	a_top_;
	int	search_num_;
	int	sort_3_num[4];

	search_num_ = array_size;
	while (search_num_ != 3)
	{
		a_top_ = cmprsd_arr_rv[1];
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

//int *の要素数が6個以下の場合のソートアルゴリズム
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
