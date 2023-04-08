/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:09:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/08 16:07:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_sort {
	int		*num;
	size_t	*num2;
	size_t	num3;
}	t_sort;

struct Deque {
	char	**before_sort;
    t_sort	*data;  // 要素を格納する配列
    int head;  // 先頭を指すインデックス
    int tail;   // 末尾を指すインデックス

    int size;   // 現在の要素数
    int capacity;   // 格納できる最大要素数
};

//配列
typedef struct s_stack {
	char	**before_sort;
	int		tail;
	int		head;
	t_sort	*data;
	size_t	size;
}	t_stack;

//utils.c
char	*ft_pram_join(char **pram_str, size_t pram_len);
int		*ft_set_arr_num(char **check_str);
void	ft_free_str(char **str);
//error.c
int		*ft_iserror(int argc, char **argv);
//error_utils.c
int		ft_isempty_pram(int argc, char **argv);
int		ft_isnot_num_value(int argc, char **argv);
int		ft_isnot_integer(char *check_str);
int		ft_is_sign_error(char *check_str);
int		ft_is_duplicate(int *check_arr_num);
//quick_sort.c
void	quick_sort(int *sort_num, size_t point, size_t standard);
void	ft_coordinate_compression(int *num, int *num_sort,
			int *num_order, size_t num_len);
#endif

/*
[5,1,2,|3,4,5]

*/