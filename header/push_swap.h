/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:09:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/15 11:48:54 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

//stack、ABの構造体
typedef struct s_ps_stack {
	int		*param_array;
	int		*sort_array;
	int		*cmprsd_arr_rv;
	size_t	array_size;
	size_t	ab_flg;
}	t_ps_stack;

//スタックAに戻す際に使用する構造体
typedef struct s_move_a {
	size_t	b_top_;
	size_t	search_num;
	size_t	search_num_next;
	size_t	search_num_flg;
	size_t	a_move_flg;
	size_t	group_move_count;
}	t_move_a;

//スタックBに移動させる構造体
typedef struct s_move_b {
	size_t	delimiter_num;
	size_t	scope_min;
	size_t	scope_max;
}	t_move_b;

//main.c
size_t	ft_array_size(int argc, char **argv);
//utils.c
char	*ft_pram_join(int argc, char **argv);
int		*ft_set_arr_num(char **check_str);
void	ft_free_str(char **str);
void	ft_reverse_coordinate_compression(t_ps_stack *ab_stack);
//error.c
void	ft_error_check(int argc, char **argv);
//error_utils.c
int		ft_isempty_pram(int argc, char **argv);
int		ft_isnot_num_value(int argc, char **argv);
int		ft_isnot_integer(char *check_str);
int		ft_is_sign_error(char *check_str);
int		ft_is_duplicate(int *check_arr_num, int argc, char **argv);
//put_error.c
void	ft_error_all_free(char *check_str, char **check_c, int *check_arr_num);
void	ft_exit_error(char *str, char **c_str, int *num);
void	ft_put_error_exit(void);
//quick_sort.c
void	ft_quick_sort(int *sort_num, size_t point, size_t standard);
//stack_utils.c
size_t	ft_stack_a_size(t_ps_stack *ab_stack);
size_t	ft_stack_b_size(t_ps_stack *ab_stack);
void	ft_swap(int *a, int *b);
//swap.c
void	ft_swap_a(t_ps_stack *ab_stack);
void	ft_swap_b(t_ps_stack *ab_stack);
void	ft_swap_ab(t_ps_stack *ab_stack);
//push.c
void	ft_push_a(t_ps_stack *ab_stack);
void	ft_push_b(t_ps_stack *ab_stack);
//rotate.c
void	ft_rotate_a(t_ps_stack *ab_stack);
void	ft_rotate_b(t_ps_stack *ab_stack);
void	ft_rotate_ab(t_ps_stack *ab_stack);
//reverse_rotate.c
void	ft_reverse_rotate_a(t_ps_stack *ab_stack);
void	ft_reverse_rotate_b(t_ps_stack *ab_stack);
void	ft_reverse_rotate_ab(t_ps_stack *ab_stack);
//long_sort.c
void	ft_long_sort(t_ps_stack *ab_stack);
bool	ft_rotate_or_reverse_rotate_check(t_ps_stack *ab_stack, int search_num);
//min_sort.c
void	ft_min_sort(t_ps_stack *ab_stack);

//TODO:後削除
void	ft_stack_print(t_ps_stack *ab_stack_);
#endif

/*
[5,1,2,|3,4,5]

*/