/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/14 22:41:43 by yshimoma         ###   ########.fr       */
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

//int配列の要素数を取得する関数
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

//引数で受け取った文字列をint配列へ変換する関数
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

//引数をint配列へ格納
//引数をソートし、int配列へ格納
//座標圧縮するint配列をmallocで確保
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
		if (ab_stack->cmprsd_arr_rv[i_] > ab_stack->cmprsd_arr_rv[i_ + 1])
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
int	main(int argc, char **argv){
	t_ps_stack	ab_stack_;

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
	// ft_stack_print(&ab_stack_);
	return (0);
}

// int	main(void){
// 	t_ps_stack	ab_stack_;
// 	// char *argv[2] = {"./push_swap", "53 70 63 81 3 20 87 79 57 38 21 35 72 100 22 40 64 26 44 8 15 74 66 30 32 73 2 11 28 46 69 94 65 68 10 12 84 62 34 95 92 36 41 16 29 75 52 71 80 99 76 23 50 33 96 0 19 37 61 24 51 6 86 9 7 58 67 47 13 83 56 43 55 45 91 25 48 59 93 60 77 27 39 85 49 31 18 17 89 97 1 88 98 14 90 42 82 54 78 4"};
// 	char *argv[2] = {"./push_swap", "995854594 1116725726 579066316 1098308372 1949288486 512988546 -2120762637 2107293831 -1547808012 -548329368 -593421432 -427235846 835053612 -1330436478 -1757696064 -936743806 63392982 -901606491 1610100791 1830908052 -848194210 996318878 2126729073 -1794451911 556739080 1738381133 -1595186165 -1078175655 2039816602 -1102332552 -887144298 -1373655864 1320218183 -521962250 1304227295 -1027038804 -2016810013 1443091492 184486476 1798090089 -1333810512 811094432 -161579280 -280535802 -711065128 310302375 -1516271126 197742839 -181985656 -601965747 685869019 -817105991 343530368 -1440399352 896562704 -1527985733 -470334351 -1488109684 402240906 -1339312929 581444053 -681949501 71058464 100793456 -457759650 -1433081026 -1496272953 -1805679659 -1524917060 -1216564605 -214928874 878819579 1679593405 1345084108 -1188204304 -342819896 1506099482 -11704537 -846831103 1776715655 1836828454 -1881573872 739919179 939956803 1524273663 759972860 -1037560172 2045948534 1053511538 -492981275 902909189 385022031 -958500335 -2022225385 696393964 -339921133 1278622212 942830893 -779803442 785536890"};
// 	int argc = 2;

// 	ab_stack_ = (t_ps_stack){0};
// 	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
// 	ft_error_check(argc, argv);
// 	ft_set_array(&ab_stack_, argc, argv);
// 	ft_printf("param_array = ");
// 	for (int i = 0; i < 100; i++) {
// 		ft_printf("%d,", ab_stack_.param_array[i]);
// 	}
// 	ft_printf("\n");

// 	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);

// 	ft_printf("sort_array = ");
// 	for (int i = 0; i < 100; i++) {
// 		ft_printf("%d,", ab_stack_.sort_array[i]);
// 	}
// 	ft_printf("\n");

// 	ft_reverse_coordinate_compression(&ab_stack_);

// 	ft_printf("cmprsd_arr_rv = ");
// 	for (int i = 1; i < 101; i++) {
// 		ft_printf("%d,", ab_stack_.cmprsd_arr_rv[i]);
// 	}
// 	ft_printf("\n");


// 	ft_is_sorted(&ab_stack_);
// 	// if (ab_stack_.array_size < 7)
// 	// 	//ft_short_sort(&ab_stack_);
// 	// else
// 	// 	//ロングソート
// 	// ft_long_sort(&ab_stack_);
// 	// ft_stack_print(&ab_stack_);
// 	return (0);
// }

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
