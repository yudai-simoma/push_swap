/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/13 22:00:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックの中身を出力する関数
// 検証用
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

	join_str_ = ft_pram_join(argc, argv);
	if (join_str_ == NULL)
		ft_put_error_exit();
	split_c_ = ft_split(join_str_, ' ');
	if (split_c_ == NULL)
	{
		free(join_str_);
		ft_put_error_exit();
	}
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

	join_str_ = ft_pram_join(argc, argv);
	if (join_str_ == NULL)
		return (NULL);
	split_c_ = ft_split(join_str_, ' ');
	if (split_c_ == NULL)
		return (NULL);
	ptr_num_ = ft_set_arr_num(split_c_);
	if (ptr_num_ == NULL)
		return (NULL);
	free(join_str_);
	ft_free_str(split_c_);
	return (ptr_num_);
}

void	ft_set_array(t_ps_stack *ab_stack, int argc, char **argv)
{
	ab_stack->array_size = ft_array_size(argc, argv);
	ab_stack->ab_flg = ab_stack->array_size;
	ab_stack->param_array = ft_convert_ptr(argc, argv);
	if (ab_stack->param_array == NULL)
		ft_put_error_exit();
	ab_stack->sort_array = ft_convert_ptr(argc, argv);
	if (ab_stack->sort_array == NULL)
	{
		free(ab_stack->param_array);
		ft_put_error_exit();
	}
	ab_stack->cmprsd_arr_rv = malloc(sizeof(int) * ab_stack->array_size + 1);
	if (ab_stack->cmprsd_arr_rv == NULL)
	{
		free(ab_stack->param_array);
		free(ab_stack->sort_array);
		ft_put_error_exit();
	}
}

//受け取った引数が昇順に並んでいるかチェック
void	ft_is_sorted(t_ps_stack *ab_stack)
{
	size_t	i_;

	i_ = 1;
	while (i_ < ab_stack->array_size - 1)
	{
		if (ab_stack->cmprsd_arr_rv[i_] < ab_stack->cmprsd_arr_rv[i_ + 1])
			return ;
		i_++;
	}
	free(ab_stack->param_array);
	free(ab_stack->sort_array);
	free(ab_stack->cmprsd_arr_rv);
	exit(1);
}

/*
 * TODO: ft_printfのライブラリを削除する（g_変数を使用しているため＼）
		エラーメッセージをwriteでかく。またerror\nのみにする
		ft_iserrorの関数名を変更する
		引数がソートされているかのチェック
		エラーチェックの確認
 */
// int	main(int argc, char **argv){
// 	t_ps_stack	ab_stack_;

// 	ab_stack_ = (t_ps_stack){0};
// 	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
// 	ft_error_check(argc, argv);
// 	ft_set_array(&ab_stack_, argc, argv);
// 	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
// 	ft_reverse_coordinate_compression(&ab_stack_);
// 	ft_is_sorted(&ab_stack_);
// 	// if (ab_stack_.array_size < 7)
// 	// 	//ft_short_sort(&ab_stack_);
// 	// else
// 	// 	//ロングソート
// 	ft_long_sort(&ab_stack_);
// 	ft_stack_print(&ab_stack_);
// 	return (0);
// }

int	main(void){
	t_ps_stack	ab_stack_;
	char *argv[1] = {"./push_swap" "0 23 243  43 45 67 4 -45 -563  73"};
	int argc = 2;

	ab_stack_ = (t_ps_stack){0};
	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
	ft_error_check(argc, argv);
	ft_set_array(&ab_stack_, argc, argv);
	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
	ft_reverse_coordinate_compression(&ab_stack_);
	ft_is_sorted(&ab_stack_);
	// if (ab_stack_.array_size < 7)
	// 	//ft_short_sort(&ab_stack_);
	// else
	// 	//ロングソート
	ft_long_sort(&ab_stack_);
	ft_stack_print(&ab_stack_);
	return (0);
}


// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//	 system("leaks -q push_swap");
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
// 	ft_quick_sort(ab_stack.sort_array, 0, ab_stack.array_size - 1);
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
