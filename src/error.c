/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:26:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 18:33:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * エラー処理の種類
 *  ・コマンドライン引数の中に空文字だけの引数があるかどうかのチェック
 *  ・コマンドライン引数の中に数値が一つもない引数があるかどうかのチェック
 *  ・コマンドライン引数の値が全て数値かどうかのチェック
 *  ・コマンドライン引数の符号が、「++」、「--」、「空欄+空欄」などのエラー対応
 *  ・コマンドライン引数の値が、intの範囲かどうかのチェック
 *  ・コマンドライン引数の値が、重複しているかのチェック
 */

/*
 * コマンドライン引数の値がエラーでなかった場合に呼ばれる
 * 引数の値の値をすべてfreeする
 */
static void	ft_error_all_free(char *check_str,
	char **check_c, int *check_arr_num)
{
	free(check_str);
	ft_free_str(check_c);
	free(check_arr_num);
}

/*
 * 引数の値が、「+」か「-」かどうかのチェック
 */
static char	ft_sing_check(char sing)
{
	if (ft_strchr("+-", sing) != NULL)
	{
		if ('-' == sing)
			return ('-');
	}
	return ('+');
}

/*
 * 引数の値が、intの範囲かどうかのチェック
 * intの範囲外ならエラー
 */
static bool	ft_ismax(long check_num, char sign_flg)
{
	if (sign_flg == '+')
	{
		if (check_num > INT_MAX)
			return (true);
	}
	else
	{
		if ((check_num * -1) < INT_MIN)
			return (true);
	}
	return (false);
}

/*
 * コマンドライン引数の値が、intの範囲かどうかのチェック
 * intの範囲外ならエラー
 */
bool	ft_is_out_scope(char **check_str)
{
	size_t	i_;
	size_t	j_;
	long	check_num_;
	char	sign_flg_;

	i_ = 0;
	while (check_str[i_] != NULL)
	{
		j_ = 0;
		sign_flg_ = ft_sing_check(check_str[i_][j_]);
		if (ft_strchr("+-", check_str[i_][j_]) != NULL)
			j_++;
		check_num_ = 0;
		while (check_str[i_][j_] != '\0')
		{
			check_num_ = (check_num_ * 10) + (check_str[i_][j_] - '0');
			if (ft_ismax(check_num_, sign_flg_))
				return (true);
			j_++;
		}
		i_++;
	}
	return (false);
}

/*
 * コマンドライン引数のエラーチェック
 * エラーがあれば、エラーメッセージを表示しプログラム終了
 */
void	ft_error_check(int argc, char **argv)
{
	char	*check_str_;
	char	**check_c_;
	int		*check_arr_num_;

	if (argc == 1 || ft_isempty_pram(argc, argv))
		exit(1);
	if (ft_isnot_num_value(argc, argv))
		ft_exit_error(NULL, NULL, NULL);
	check_str_ = ft_pram_join(argc, argv);
	if (check_str_ == NULL)
		ft_exit_error(NULL, NULL, NULL);
	if (ft_isnot_integer(check_str_) || ft_is_sign_error(check_str_))
		ft_exit_error(check_str_, NULL, NULL);
	check_c_ = ft_split(check_str_, ' ');
	if (check_c_ == NULL)
		ft_exit_error(check_str_, NULL, NULL);
	if (ft_is_out_scope(check_c_))
		ft_exit_error(check_str_, check_c_, NULL);
	check_arr_num_ = ft_set_arr_num(check_c_);
	if (check_arr_num_ == NULL)
		ft_exit_error(check_str_, check_c_, NULL);
	if (ft_is_duplicate(check_arr_num_, argc, argv))
		ft_exit_error(check_str_, check_c_, check_arr_num_);
	ft_error_all_free(check_str_, check_c_, check_arr_num_);
	return ;
}
