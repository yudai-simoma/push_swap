/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:24:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/17 18:23:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * コマンドライン引数の値がエラーの場合に呼ばれる
 * 引数の値がNULLでなければfreeもする
 */
void	ft_exit_error(char *str, char **c_str, int *num)
{
	ft_putendl_fd("error", 2);
	if (str != NULL)
		free(str);
	if (c_str != NULL)
		ft_free_str(c_str);
	if (num != NULL)
		free(num);
	exit(1);
}

/*
 * mallocなどの処理失敗時に呼ばれる
 */
void	ft_put_error_exit(void)
{
	ft_putendl_fd("error", 2);
	exit(1);
}
