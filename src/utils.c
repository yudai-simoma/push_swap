/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:34:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/08 12:28:21 by yshimoma         ###   ########.fr       */
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
int	*ft_set_arr_num(char **check_str)
{
	int		*arr_check_;
	size_t	i_;

	i_ = 0;
	while (check_str[i_] != NULL)
		i_++;
	arr_check_ = (int *)malloc(sizeof(int) * i_);
	i_ = 0;
	while (check_str[i_] != NULL)
	{
		arr_check_[i_] = atoi(check_str[i_]);
		i_++;
	}
	return (arr_check_);
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
