/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/09 20:24:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_print(t_ps_stack *ab_stack_)
{
	size_t i = 0;

	ft_printf("num_order = ");
	for (size_t j = 0; j < ab_stack_->array_size + 1; j++) {
		ft_printf("%d,", ab_stack_->cmprsd_arr_rv[j]);
	}
	ft_printf("\n");

	ft_printf("num[a]    = ");
	i = ab_stack_->ab_flg;
	while (i != 0)
	{
		ft_printf("%d,", ab_stack_->cmprsd_arr_rv[i]);
		i--;
	}
	i = 0;
	while (i < ab_stack_->ab_flg + 1)
		i++;
	ft_printf("\nnum[b]    = ");
	while (i < ab_stack_->array_size + 1)
	{
		ft_printf("%d,", ab_stack_->cmprsd_arr_rv[i]);
		i++;
	}
	ft_printf("\n");
}

size_t	ft_array_size(int argc, char **argv)
{
	char	*join_str_;
	char	**split_c_;
	size_t	i_;

	join_str_ = ft_pram_join(argv, argc - 1);
	split_c_ = ft_split(join_str_, ' ');
	i_ = 0;
	while (split_c_[i_] != NULL)
		i_++;
	free(join_str_);
	ft_free_str(split_c_);
	return (i_);
}

int	*ft_convert_ptr(int argc, char **argv)
{
	char	*join_str_;
	char	**split_c_;
	int		*ptr_num_;

	join_str_ = ft_pram_join(argv, argc - 1);
	split_c_ = ft_split(join_str_, ' ');
	ptr_num_ = ft_set_arr_num(split_c_);
	free(join_str_);
	ft_free_str(split_c_);
	return (ptr_num_);
}

/*
 * TODO: ft_printfのライブラリを削除する（g_変数を使用しているため＼）
		エラーメッセージをwriteでかく。またerror\nのみにする
		ft_iserrorの関数名を変更する
		引数がソートされているかのチェック
		エラーチェックの確認
 */
int	main(void){
	t_ps_stack	ab_stack_;
	char *argv[3] = {"3 +6 2 -5 1 +7 -4 10", "9 -12 +11  15 8 14 +13 2147483647","2147483646 -2147483648 -2147483647 0"};
	int argc = 4;

	ab_stack_ = (t_ps_stack){0};
	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
	ft_iserror(argc, argv);
	ab_stack_.param_array = ft_convert_ptr(argc, argv);
	ab_stack_.sort_array = ft_convert_ptr(argc, argv);
	ab_stack_.array_size = ft_array_size(argc, argv);
	quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
	//freeする
	ft_reverse_coordinate_compression(&ab_stack_);
	// ab_stack_.ab_flg = ab_stack_.array_size;
	ab_stack_.ab_flg = 10;

	ft_stack_print(&ab_stack_);
	
	ft_stack_print(&ab_stack_);
	return (0);
}
// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }


// int	main(void){
// 	t_ps_stack	ab_stack;
// 	char *argv[3] = {"3 +6 2 -5 1 +7 -4 10", "9 -12 +11  15 8 14 +13 2147483647","2147483646 -2147483648 -2147483647 0"};
// 	int argc = 4;

// 	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
// 	ft_iserror(argc, argv);
// 	ab_stack.param_array = ft_convert_ptr(argc, argv);
// 	ab_stack.sort_array = ft_convert_ptr(argc, argv);
// 	ab_stack.array_size = ft_array_size(argc, argv);
// 	quick_sort(ab_stack.sort_array, 0, ab_stack.array_size - 1);
// 	ft_printf ("num = ");
// 	for (size_t i = 0; i < ab_stack.array_size; i++) {
// 		ft_printf("%d,", ab_stack.param_array[i]);
// 	}
// 	ft_printf("\nnum_sort = ");
// 	for (size_t i = 0; i < ab_stack.array_size; i++) {
// 		ft_printf("%d,", ab_stack.sort_array[i]);
// 	}
// 	ab_stack.cmprsd_arr_rv = (int *)malloc(sizeof(int) * ab_stack.array_size);
// 	ft_coordinate_compression(ab_stack.param_array, ab_stack.sort_array, ab_stack.cmprsd_arr_rv, ab_stack.array_size);
// 	ft_printf("\nnum_order = ");
// 	for (size_t i = 0; i < ab_stack.array_size; i++) {
// 		ft_printf("%d,", ab_stack.cmprsd_arr_rv[i]);
// 	}
// 	return (0);
// }











/*
[5, 4, 9, 2, 4, 3,| 8 ,5 ]
 3, 5, 4, 9, 2, 4
a = 3




*/