/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:09:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/06 21:46:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

struct Deque {
	char	**before_sort;
    t_sort* data;  // 要素を格納する配列
    int head;  // 先頭を指すインデックス
    int tail;   // 末尾を指すインデックス

    int size;   // 現在の要素数
    int capacity;   // 格納できる最大要素数
};

typedef struct s_sort {
	int		*num;
	size_t	*num2;
	size_t	num3;
}	t_sort;

//配列
typedef struct s_stack {
	char	**before_sort;
	int		tail;
	int		head;
	t_sort	*data;
	size_t	size;
}	t_stack;

#endif

/*
[5,1,2,|3,4,5]

*/