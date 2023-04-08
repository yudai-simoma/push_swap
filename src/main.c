/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/08 17:00:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void){
	int	*num;
	int	*num_sort;
	int	*num_order;
	char *argv[3] = {"3 +6 2 -5 1 +7 -4 10", "9 -12 +11  15 8 14 +13 2147483647","2147483646 -2147483648 -2147483647 0"};
	int argc = 4;

	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
	num = ft_iserror(argc, argv);
	ft_printf("size %z\n", sizeof(num) / sizeof(num[0]));
	// sizeof(arr) / sizeof(arr[0]);
	num_sort = num;
	// num_sort = ft_iserror(argc, argv);
	quick_sort(num_sort, 0, 20 - 1);
	ft_printf ("num = ");
	for (int i = 0; i < 20; i++) {
		ft_printf("%d,", num[i]);
	}
	ft_printf("\nnum_sort = ");
	for (int i = 0; i < 20; i++) {
		ft_printf("%d,", num_sort[i]);
	}
	num_order = (int *)malloc(sizeof(int) * 20);
	ft_coordinate_compression(num, num_sort, num_order, 20);
	ft_printf("\nnum_order = ");
	for (int i = 0; i < 20; i++) {
		ft_printf("%d,", num_order[i]);
	}
	return (0);
}

// int main(void){
// 	// Your code here!
// 	int *num;
// 	int *num_sort;
// 	int *num_order;

// 	num = (int *)malloc(sizeof(int) * 7);
// 	num_sort = (int *)malloc(sizeof(int) * 7);
// 	num_order = (int *)malloc(sizeof(int) * 7);
// 	create(num, num_sort);
// 	quick_sort(num_sort, 0, 7 - 1);
// 	ft_printf	("num = ");
// 	for (int i = 0; i < 7; i++) {
// 		ft_printf	("%d,", num[i]);
// 	}
// 	ft_printf	("\nnum_sort = ");
// 	for (int i = 0; i < 7; i++) {
// 		ft_printf	("%d,", num_sort[i]);
// 	}
// 	ft_coordinate_compression(num, num_sort, num_order, 7);
// 	ft_printf	("\nnum_order = ");
// 	for (int i = 0; i < 7; i++) {
// 		ft_printf	("%d,", num_order[i]);
// 	}
// 	return (0);
// }
