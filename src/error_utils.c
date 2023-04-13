/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:42:26 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/13 22:01:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//引数が全てからか
int	ft_isempty_pram(int argc, char **argv)
{
	int		i_;
	size_t	j_;
	size_t	num_count_;

	i_ = 0;
	while (i_ < argc - 1)
	{
		j_ = 0;
		num_count_ = 0;
		while (argv[i_][j_] != '\0')
		{
			if (argv[i_][j_] != ' ')
				return (false);
			j_++;
		}
		i_++;
	}
	return (true);
}

//1つの引数の中に数値が一つもない
int	ft_isnot_num_value(int argc, char **argv)
{
	int		i_;
	size_t	j_;
	size_t	num_count_;

	i_ = 1;
	while (i_ < argc)
	{
		j_ = 0;
		num_count_ = 0;
		while (argv[i_][j_] != '\0')
		{
			if (ft_isdigit(argv[i_][j_]))
				num_count_++;
			j_++;
		}
		if (num_count_ == 0)
			return (true);
		i_++;
	}
	return (false);
}

//整数でない
int	ft_isnot_integer(char *check_str)
{
	size_t	i_;
	char	c_;

	i_ = 0;
	while (check_str[i_] != '\0')
	{
		c_ = check_str[i_];
		if (!ft_isdigit(c_) && ft_strchr(" +-", c_) == NULL)
			return (true);
		i_++;
	}
	return (false);
}

//++, --のエラー処理の対応、空欄+空欄のエラー処理
int	ft_is_sign_error(char *check_str)
{
	size_t	i_;

	i_ = 0;
	while (check_str[i_] != '\0')
	{
		if (ft_strchr("+-", check_str[i_]) != NULL
			&& !ft_isdigit(check_str[i_ + 1]))
			return (true);
		i_++;
	}
	return (false);
}

//重複している
//TODO:ここではサイズを取得しているが、本来は構造体の中に入っている
int	ft_is_duplicate(int *check_arr_num, int argc, char **argv)
{
	size_t	i_;
	size_t	j_;
	size_t	dup_count_;
	size_t	array_size_;

	i_ = 0;
	array_size_ = ft_array_size(argc, argv);
	while (i_ < array_size_)
	{
		j_ = 0;
		dup_count_ = 0;
		while (j_ < array_size_)
		{
			if (check_arr_num[i_] == check_arr_num[j_])
				dup_count_++;
			j_++;
		}
		if (dup_count_ != 1)
			return (true);
		i_++;
	}
	return (false);
}
