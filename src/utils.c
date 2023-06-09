/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:34:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/23 13:09:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * joinで結合する際に、間にスペースを入れる処理
 */
static char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*str_;
	char	*free_str_;

	free_str_ = (char *)s1;
	str_ = ft_strjoin(s1, " ");
	free(free_str_);
	if (str_ == NULL)
		return (NULL);
	free_str_ = str_;
	str_ = ft_strjoin(str_, s2);
	free(free_str_);
	if (str_ == NULL)
		return (NULL);
	return (str_);
}

/*
 * コマンドライン引数で受け取った**argv を char*に変換
 */
char	*ft_pram_join(int argc, char **argv)
{
	char	*malloc_str_;
	int		i_;

	i_ = 1;
	while (i_ < argc)
	{
		if (i_ == 1)
		{
			malloc_str_ = ft_strjoin("", argv[i_]);
			if (malloc_str_ == NULL)
				return (NULL);
		}
		else
		{
			malloc_str_ = ft_strjoin_space(malloc_str_, argv[i_]);
			if (malloc_str_ == NULL)
				return (NULL);
		}
		i_++;
	}
	return (malloc_str_);
}

/*
 * char** を int*に変換
 * ["123","43","777"] → [0]=123, [1]=42, [2]=777
 */
int	*ft_set_arr_num(char **str)
{
	int		*arr_num_;
	size_t	i_;

	i_ = 0;
	while (str[i_] != NULL)
		i_++;
	arr_num_ = (int *)malloc(sizeof(int) * i_);
	if (arr_num_ == NULL)
		return (NULL);
	i_ = 0;
	while (str[i_] != NULL)
	{
		arr_num_[i_] = atoi(str[i_]);
		i_++;
	}
	return (arr_num_);
}

/*
 * char** をfreeする
 * ※ft_splitを使用した値しか来ないため、NULLが必ず入っている
 */
void	ft_free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
 * 座標圧縮する関数
 * 「32 53 1 33 98」→「2 4 1 3 5」
 * 配列へ後ろから入れている。（今回のデータの持ち方が逆から持つ必要があるため）
 */
void	ft_reverse_coordinate_compression(t_ps_stack *ab_stack)
{
	size_t	pi_;
	size_t	si_;
	size_t	ci_;
	size_t	malloc_size;

	malloc_size = ab_stack->array_size;
	pi_ = 0;
	ci_ = ab_stack->array_size;
	while (pi_ < malloc_size)
	{
		si_ = 0;
		while (si_ < malloc_size)
		{
			if (ab_stack->param_array[pi_] == ab_stack->sort_array[si_])
			{
				ab_stack->cmprsd_arr_rv[ci_] = si_ + 1;
				ci_--;
			}
			si_++;
		}
		pi_++;
	}
	ab_stack->cmprsd_arr_rv[0] = 0;
}
