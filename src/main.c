/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:11:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 21:31:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * int配列の要素数を取得する関数
 */
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

/*
 * コマンドライン引数で受け取った文字列をint配列へ変換する関数
 */
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

/*
 * ・コマンドライン引数をint配列へ格納
 * ・コマンドライン引数をint配列へ格納しその値をソート
 * ・座標圧縮するint配列をmallocで確保
 * 		mallocで +1しているのは、添え字0番目には値を入れないため
 */
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

/*
 * 受け取った引数が昇順に並んでいるかチェック
 * 昇順に並んでいたらfreeをし、プログラム終了
 */
//TODO:ソートプログラムが間違っている
void	ft_is_sorted(t_ps_stack *ab_stack)
{
	size_t	i_;
	size_t	flg_;

	i_ = ab_stack->ab_flg - 1;
	flg_ = 0;
	while (i_)
	{
		if (ab_stack->cmprsd_arr_rv[i_] > ab_stack->cmprsd_arr_rv[i_ - 1])
			flg_++;
		i_--;
	}
	if (flg_ == (ab_stack->array_size - 1))
	{
		free(ab_stack->param_array);
		free(ab_stack->sort_array);
		free(ab_stack->cmprsd_arr_rv);
		exit(1);
	}
	return ;
}

/*
 * プログラムの一番初めに呼ばれる関数
 * デバック用にプリプロセッサを記載している
 */
// int	main(int argc, char **argv)
// {
// 	t_ps_stack	ab_stack_;

// 	ab_stack_ = (t_ps_stack){0};
// 	ft_error_check(argc, argv);
// 	ft_set_array(&ab_stack_, argc, argv);
// 	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
// 	ft_reverse_coordinate_compression(&ab_stack_);
// 	ft_is_sorted(&ab_stack_);
// 	if (ab_stack_.array_size < 7)
// 		ft_min_sort(&ab_stack_);
// 	else
// 		ft_long_sort(&ab_stack_);
// 	free(ab_stack_.param_array);
// 	free(ab_stack_.sort_array);
// 	free(ab_stack_.cmprsd_arr_rv);
// 	return (0);
// }

// リークチェックの関数
// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	 system("leaks -q push_swap");
// }

#if COMP_DEF_FLAG == 1
int main(int argc, char **argv) {
#else
int	main(void){
	char *argv[2] = {"./push_swap", "1 2"};
	int argc = 2;
#endif
	t_ps_stack	ab_stack_;

	ab_stack_ = (t_ps_stack){0};
	ft_error_check(argc, argv);
	ft_set_array(&ab_stack_, argc, argv);
	ft_quick_sort(ab_stack_.sort_array, 0, ab_stack_.array_size - 1);
	ft_reverse_coordinate_compression(&ab_stack_);
	ft_is_sorted(&ab_stack_);
	if (ab_stack_.array_size < 7)
		ft_min_sort(&ab_stack_);
	else
		ft_long_sort(&ab_stack_);
	free(ab_stack_.param_array);
	free(ab_stack_.sort_array);
	free(ab_stack_.cmprsd_arr_rv);
	return (0);
}

// /*
//  * スタックの中身を出力する関数
//  * 検証用
//  */
void	ft_stack_print(t_ps_stack *ab_stack)
{
	size_t i = 0;

	fprintf(stderr, "num_order = ");
	for (size_t j = ab_stack->ab_flg; j < ab_stack->array_size + 1; j--) {
		fprintf(stderr, "%d,", ab_stack->cmprsd_arr_rv[j]);
	}
	fprintf(stderr, "\n");	
	fprintf(stderr, "\nnum[a]    = ");
	i = ab_stack->ab_flg;
	while (i != 0)
	{
		fprintf(stderr, "%d,", ab_stack->cmprsd_arr_rv[i]);
		i--;
	}
	// i = 1;
	// while (i < ft_stack_a_size(ab_stack) + 1)
	// {
	// 	fprintf(stderr, "%d,", ab_stack->cmprsd_arr_rv[i]);
	// 	i++;
	// }
	i = 0;
	while (i < ab_stack->ab_flg + 1)
		i++;
	fprintf(stderr, "\nnum[b]    = ");
	while (i < ab_stack->array_size + 1)
	{
		fprintf(stderr, "%d,", ab_stack->cmprsd_arr_rv[i]);
		i++;
	}
	fprintf(stderr, "\n");
}
