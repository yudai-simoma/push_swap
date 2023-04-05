/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:32:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/05 19:34:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void ft_swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

int	partition(int *sort_num, size_t point, size_t standard)
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

void	create(int *num, int *num_sort)
{
	num[0] = 32;
	num[1] = 435;
	num[2] = -4;
	num[3] = -43;
	num[4] = 342;
	num[5] = 143;
	num[6] = 534;
	num_sort[0] = 32;
	num_sort[1] = 435;
	num_sort[2] = -4;
	num_sort[3] = -43;
	num_sort[4] = 342;
	num_sort[5] = 143;
	num_sort[6] = 534;
}

void	ft_coordinate_compression(int *num, int *num_sort, int *num_order, size_t num_len)
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

int main(void){
	// Your code here!
	int *num;
	int *num_sort;
	int *num_order;

	num = (int *)malloc(sizeof(int) * 7);
	num_sort = (int *)malloc(sizeof(int) * 7);
	num_order = (int *)malloc(sizeof(int) * 7);
	create(num, num_sort);
	quick_sort(num_sort, 0, 7 - 1);
	printf("num = ");
	for (int i = 0; i < 7; i++) {
		printf("%d,", num[i]);
	}
	printf("\nnum_sort = ");
	for (int i = 0; i < 7; i++) {
		printf("%d,", num_sort[i]);
	}
	ft_coordinate_compression(num, num_sort, num_order, 7);
	printf("\nnum_order = ");
	for (int i = 0; i < 7; i++) {
		printf("%d,", num_order[i]);
	}
	return (0);
}
