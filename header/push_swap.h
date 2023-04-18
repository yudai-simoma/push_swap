/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:09:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/18 20:11:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# ifndef COMP_DEF_FLAG
#  define COMP_DEF_FLAG 1
# endif

//stack、ABの構造体
typedef struct s_ps_stack {
	int		*param_array;
	int		*sort_array;
	int		*cmprsd_arr_rv;
	size_t	array_size;
	size_t	ab_flg;
}	t_ps_stack;

//スタック移動させる構造体
typedef struct s_move {
	size_t	section_count;
	int		section_num;
	int		top_num;
	int		search_num;
	int		search_num_more;
	size_t	a_move_flg;
}	t_move;

//main.c
size_t	ft_array_size(int argc, char **argv);
int		*ft_convert_ptr(int argc, char **argv);
void	ft_set_array(t_ps_stack *ab_stack, int argc, char **argv);
void	ft_is_sorted(t_ps_stack *ab_stack);
//utils.c
char	*ft_pram_join(int argc, char **argv);
int		*ft_set_arr_num(char **str);
void	ft_free_str(char **str);
void	ft_reverse_coordinate_compression(t_ps_stack *ab_stack);
//error.c
bool	ft_is_out_scope(char **check_str);
void	ft_error_check(int argc, char **argv);
//error_utils.c
bool	ft_isempty_pram(int argc, char **argv);
bool	ft_isnot_num_value(int argc, char **argv);
bool	ft_isnot_integer(char *check_str);
bool	ft_is_sign_error(char *check_str);
bool	ft_is_duplicate(int *check_arr_num, int argc, char **argv);
//put_error.c
void	ft_exit_error(char *str, char **c_str, int *num);
void	ft_put_error_exit(void);
//quick_sort.c
void	ft_quick_sort(int *sort_num, size_t point, size_t standard);
//stack.c
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
//long_sort_utils.c
void	ft_ascending_move_a(t_ps_stack *ab_stack, t_move *move_a);
//min_sort.c
void	ft_min_sort(t_ps_stack *ab_stack);
//min_sort_utils.c
void	ft_sort_size_max_6(t_ps_stack *ab_stack);

//TODO:後削除
void	ft_stack_print(t_ps_stack *ab_stack_);
#endif

/*
[5,1,2,|3,4,5]

*/