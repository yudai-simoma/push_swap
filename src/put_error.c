/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:24:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/10 21:25:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_all_free(char *check_str, char **check_c, int *check_arr_num)
{
	free(check_str);
	ft_free_str(check_c);
	free(check_arr_num);
}

//エラー内容によって出力内容を変える
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

void	ft_put_error_exit(void)
{
	ft_putendl_fd("error", 2);
	exit(1);
}
