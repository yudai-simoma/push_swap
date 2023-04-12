/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:32:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/12 10:22:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//クイックソートでのパーティション
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

//クイックソートで並べ替え
void	ft_quick_sort(int *sort_num, size_t point, size_t standard)
{
	size_t	next_p_;

	if (point >= standard)
		return ;
	next_p_ = partition(sort_num, point, standard);
	ft_quick_sort(sort_num, next_p_ + 1, standard);
	if (next_p_ != 0)
		ft_quick_sort(sort_num, 0, next_p_ - 1);
	else
		ft_quick_sort(sort_num, 0, 0);
}
