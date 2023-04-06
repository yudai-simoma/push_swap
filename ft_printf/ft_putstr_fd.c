/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:33:11 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/03/20 18:35:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 文字列を出力する
*/
void	ft_putstr_fd_p(char *s, int fd)
{
	int	x;

	x = 0;
	if (s == NULL)
		return ;
	if (fd < 0)
		return ;
	x = write(fd, s, ft_strlen_p(s));
	if (x == -1)
		g_error_flg = -1;
}
