/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/15 19:00:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// スタックの中身を出力する関数
// 検証用
void	ft_stack_print(t_ps_stack *ab_stack_)
{
	size_t i = 0;

	fprintf(stderr, "num_order = ");
	for (size_t j = 0; j < ab_stack_->array_size + 1; j++) {
		fprintf(stderr, "%d,", ab_stack_->cmprsd_arr_rv[j]);
	}
	fprintf(stderr, "\n");

	// for (size_t i = 0; i < ab_stack_->array_size; i++)
	// {
	// 	if (i == ab_stack_->ab_flg)
	// 	{
	// 		fprintf(stderr, "| ");
	// 	}
	// 	fprintf(stderr, "%d ", ab_stack_->cmprsd_arr_rv[i]);
		
	// }
	// fprintf(stderr, "\n");
	

	fprintf(stderr, "\nnum[a]    = ");
	i = ab_stack_->ab_flg;
	while (i != 0)
	{
		fprintf(stderr, "%d,", ab_stack_->cmprsd_arr_rv[i]);
		i--;
	}
	i = 0;
	while (i < ab_stack_->ab_flg + 1)
		i++;
	fprintf(stderr, "\nnum[b]    = ");
	while (i < ab_stack_->array_size + 1)
	{
		fprintf(stderr, "%d,", ab_stack_->cmprsd_arr_rv[i]);
		i++;
	}
	fprintf(stderr, "\n");
}
//1,2,3,43,45,|

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
	size_t	flg_;

	i_ = 1;
	flg_ = 1;
	while (i_ < ab_stack->array_size - 1)
	{
		if (ab_stack->cmprsd_arr_rv[i_] < ab_stack->cmprsd_arr_rv[i_ + 1])
			flg_++;
		i_++;
	}
	if (flg_ == ab_stack->array_size)
	{
		free(ab_stack->param_array);
		free(ab_stack->sort_array);
		free(ab_stack->cmprsd_arr_rv);
		exit(1);
	}
	return ;
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
// 	ft_error_check(argc, argv);
// 	ft_set_array(&ab_stack_, argc, argv);
// 	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
// 	ft_reverse_coordinate_compression(&ab_stack_);
// 	ft_is_sorted(&ab_stack_);

// 	// ft_printf("param_array = ");
// 	// for (size_t i = 0; i < ab_stack_.array_size; i++) {
// 	// 	ft_printf("%d,", ab_stack_.param_array[i]);
// 	// }
// 	// ft_printf("\n");

// 	// ft_printf("sort_array = ");
// 	// for (size_t i = 0; i < ab_stack_.array_size; i++) {
// 	// 	ft_printf("%d,", ab_stack_.sort_array[i]);
// 	// }
// 	// ft_printf("\n");

// 	// ft_printf("cmprsd_arr_rv = ");
// 	// for (size_t i = 1; i < ab_stack_.array_size + 1; i++) {
// 	// 	ft_printf("%d,", ab_stack_.cmprsd_arr_rv[i]);
// 	// }
// 	// ft_printf("\n");

// 	if (ab_stack_.array_size < 7)
// 		ft_min_sort(&ab_stack_);
// 	else
// 		ft_long_sort(&ab_stack_);
// 	// ft_stack_print(&ab_stack_);
// 	free(ab_stack_.param_array);
// 	free(ab_stack_.sort_array);
// 	free(ab_stack_.cmprsd_arr_rv);
// 	return (0);
// }

int	main(void){
	t_ps_stack	ab_stack_;
	char *argv[2] = {"./push_swap", "-1627938544 -108209547 -141775263 761404010 -1470852912 256563088 922296746 282171420 1178079131 -1877248141 648274901 1059957831 1575202097 -653943293 -766978320 -1549102263 -84541118 935493574 -1201812994 1035370470 1393949608 -528738572 -1924435512 1540164208 1191990169 42799422 241310635 195018452 -1703400146 1735010611 230408414 1960734545 796991510 128830925 665025219 8813107 108957507 461561254 -1774443347 1433042585 -1812066683 553845629 -772565081 192744897 -972546456 -426149472 -276336036 -296261853 769582457 1099095902 -742970907 -351078438 -139725258 209537666 1308191889 30389110 453869794 -1504973335 -1513395088 1907947646 1801421485 145852485 -46715082 -1588742350 888906472 -301020630 1244772242 -1607487264 -145727332 -2104644148 -1186298237 -234935257 -1987093584 367939095 -94667244 1838460776 -2054385535 966177186 1646704281 -858078582 1620451142 -1537588390 334721555 527654968 69914615 -630863932 40196317 -856344802 1269997276 -370888389 609481273 -1855172057 35014835 -2000533930 2086300120 -339724879 -408312745 -98322058 -662622024 -1800574422"};
	// char *argv[2] = {"./push_swap", "607102189 1231087918 -2027594496 -1570825554 -1606185201 1968031746 1490159030 -1765407871 1664553377 -1833536760 70283109 -2081830741 997875396 -650175954 -2007435249 938274055 -1476469588 1973304387 -300827087 -2115307307 -1233119434 1351178703 1721534074 1692155108 1052932826 830021679 882574257 -1772395419 1778488430 1764906516 -1566750309 -253836030 363303446 -698405739 -797611676 1285214712 465774210 -913238478 -348605499 74352630 -1931679975 -606188109 1512021662 1359995582 1278912665 1788050916 -1536017879 -1793912150 -957449767 -467472615 195609941 -1874440526 459755391 597823101 -1337389598 407466631 1022868543 -1808498275 1230749461 2063528572 1965837653 -196778638 -1030656091 -443726413 701285232 -1060215050 -155002893 1463825271 -935199105 938827220 73950215 453384634 1923005175 1898365776 -475928477 -1298599326 -820123409 -199610841 -1568455907 -1142836048 1884986701 -177369026 1828249397 -504398689 222553406 -957951395 2115796245 1595454613 1343541873 -491412907 251936646 2097224202 1807019203 -301299738 1393163832 1527587947 632717273 -234048027 -355056860 -1252164184"};
	int argc = 2;

	ab_stack_ = (t_ps_stack){0};
	ft_error_check(argc, argv);
	ft_set_array(&ab_stack_, argc, argv);
	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
	ft_reverse_coordinate_compression(&ab_stack_);

	// ft_printf("param_array = ");
	// for (size_t i = 0; i < ab_stack_.array_size; i++) {
	// 	ft_printf("%d,", ab_stack_.param_array[i]);
	// }
	// ft_printf("\n");

	// ft_printf("sort_array = ");
	// for (size_t i = 0; i < ab_stack_.array_size; i++) {
	// 	ft_printf("%d,", ab_stack_.sort_array[i]);
	// }
	// ft_printf("\n");

	// ft_printf("cmprsd_arr_rv = ");
	// for (size_t i = 1; i < ab_stack_.array_size + 1; i++) {
	// 	ft_printf("%d,", ab_stack_.cmprsd_arr_rv[i]);
	// }
	// ft_printf("\n");

	ft_is_sorted(&ab_stack_);
	if (ab_stack_.array_size < 7)
		ft_min_sort(&ab_stack_);
	else
		ft_long_sort(&ab_stack_);
	// ft_stack_print(&ab_stack_);
	free(ab_stack_.param_array);
	free(ab_stack_.sort_array);
	free(ab_stack_.cmprsd_arr_rv);
	return (0);
}




// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	 system("leaks -q push_swap");
// }

	// ft_printf("param_array = ");
	// for (int i = 0; i < 100; i++) {
	// 	ft_printf("%d,", ab_stack_.param_array[i]);
	// }
	// ft_printf("\n");


	// ft_printf("sort_array = ");
	// for (int i = 0; i < 100; i++) {
	// 	ft_printf("%d,", ab_stack_.sort_array[i]);
	// }
	// ft_printf("\n");



	// ft_printf("cmprsd_arr_rv = ");
	// for (int i = 1; i < 101; i++) {
	// 	ft_printf("%d,", ab_stack_.cmprsd_arr_rv[i]);
	// }
	// ft_printf("\n");