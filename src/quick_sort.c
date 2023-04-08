/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:32:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/08 16:06:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

static int	partition(int *sort_num, size_t point, size_t standard)
{
	size_t	i_;

	i_ = point;
	while (i_ < standard)
	{
		if (sort_num[i_] < sort_num[standard])
		{
			if (i_ != point)
				ft_swap(&sort_num[i_], &sort_num[point]);
			point++;
		}
		i_++;
	}
	ft_swap(&sort_num[standard], &sort_num[point]);
	return (point);
}

void	quick_sort(int *sort_num, size_t point, size_t standard)
{
	size_t	next_p_;

	if (point >= standard)
		return ;
	next_p_ = partition(sort_num, point, standard);
	quick_sort(sort_num, next_p_ + 1, standard);
	if (next_p_ != 0)
		quick_sort(sort_num, 0, next_p_ - 1);
	else
		quick_sort(sort_num, 0, 0);
}

void	ft_coordinate_compression(int *num, int *num_sort,
	int *num_order, size_t num_len)
{
	size_t	i_;
	size_t	si_;
	size_t	oi_;

	i_ = 0;
	oi_ = 0;
	while (i_ < num_len)
	{
		si_ = 0;
		while (si_ < num_len)
		{
			if (num[i_] == num_sort[si_])
			{
				num_order[oi_] = si_;
				oi_++;
			}
			si_++;
		}
		i_++;
	}
}
