/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:34:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/12 14:24:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//joinで結合する際に、間にスペースを入れる処理
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

//コマンドライン引数で受け取ったchar* を char*に変換
char	*ft_pram_join(char **pram_str, size_t pram_len)
{
	char	*malloc_str_;
	size_t	i_;

	i_ = 0;
	while (i_ < pram_len)
	{
		if (i_ == 0)
		{
			malloc_str_ = ft_strjoin("", pram_str[i_]);
			if (malloc_str_ == NULL)
				return (NULL);
		}
		else
		{
			malloc_str_ = ft_strjoin_space(malloc_str_, pram_str[i_]);
			if (malloc_str_ == NULL)
				return (NULL);
		}
		i_++;
	}
	return (malloc_str_);
}

//char** を int*に変換
int	*ft_set_arr_num(char **str)
{
	int		*arr_num_;
	size_t	i_;

	i_ = 0;
	while (str[i_] != NULL)
		i_++;
	arr_num_ = (int *)malloc(sizeof(int) * i_);
	i_ = 0;
	while (str[i_] != NULL)
	{
		arr_num_[i_] = atoi(str[i_]);
		i_++;
	}
	return (arr_num_);
}

//2次元配列をfreeする
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

//座標圧縮する関数
void	ft_reverse_coordinate_compression(t_ps_stack *ab_stack)
{
	size_t	i_;
	size_t	si_;
	size_t	oi_;
	size_t	malloc_size;

	malloc_size = ab_stack->array_size + 1;
	i_ = 0;
	oi_ = malloc_size - 1;
	while (i_ < malloc_size - 1)
	{
		si_ = 1;
		while (si_ < malloc_size)
		{
			if (ab_stack->param_array[i_] == ab_stack->sort_array[si_])
			{
				ab_stack->cmprsd_arr_rv[oi_] = si_;
				oi_--;
			}
			si_++;
		}
		i_++;
	}
	ab_stack->cmprsd_arr_rv[oi_] = 0;
}
// 5,1,0,18,19,15,16,11,17,14,2,12,13,4,10,6,3,7,9,8,
// 0,5,1,0,18,19,15,16,11,17,14,2,12,13,4,10,6,3,7,9,