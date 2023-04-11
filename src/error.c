/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:26:16 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/11 21:06:40 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//エラー処理

// typedef struct s_error
// {
// 	char *check_str;
// 	char **check_c;
// 	int *check_arr_num;
// 	size_t arr_num;
// }   t_error;

static char	ft_sing_check(char sing)
{
	if (ft_strchr("+-", sing) != NULL)
	{
		if ('-' == sing)
			return ('-');
	}
	return ('+');
}

static int	ft_ismax(long check_num, char sign_flg)
{
	if (sign_flg == '+')
	{
		if (check_num > INT_MAX)
			return (true);
	}
	else
	{
		if ((check_num * -1) < INT_MIN)
			return (true);
	}
	return (false);
}

//intの範囲内でない
static int	ft_is_out_scope(char **check_str)
{
	size_t	i_;
	size_t	j_;
	long	check_num_;
	char	sign_flg_;

	i_ = 0;
	while (check_str[i_] != NULL)
	{
		j_ = 0;
		sign_flg_ = ft_sing_check(check_str[i_][j_]);
		if (ft_strchr("+-", check_str[i_][j_]) != NULL)
			j_++;
		check_num_ = 0;
		while (check_str[i_][j_] != '\0')
		{
			check_num_ = (check_num_ * 10) + (check_str[i_][j_] - '0');
			if (ft_ismax(check_num_, sign_flg_))
				return (true);
			j_++;
		}
		i_++;
	}
	return (false);
}

void	ft_error_check(int argc, char **argv)
{
	char	*check_str_;
	char	**check_c_;
	int		*check_arr_num_;

	if (argc == 1 || ft_isempty_pram(argc, argv))
		exit(1);
	if (ft_isnot_num_value(argc, argv))
		ft_exit_error(NULL, NULL, NULL);
	check_str_ = ft_pram_join(argv, argc - 1);
	if (check_str_ == NULL)
		ft_exit_error(NULL, NULL, NULL);
	if (ft_isnot_integer(check_str_) || ft_is_sign_error(check_str_))
		ft_exit_error(check_str_, NULL, NULL);
	check_c_ = ft_split(check_str_, ' ');
	if (check_c_ == NULL)
		ft_exit_error(check_str_, NULL, NULL);
	if (ft_is_out_scope(check_c_))
		ft_exit_error(check_str_, check_c_, NULL);
	check_arr_num_ = ft_set_arr_num(check_c_);
	if (check_arr_num_ == NULL)
		ft_exit_error(check_str_, check_c_, NULL);
	if (ft_is_duplicate(check_arr_num_))
		ft_exit_error(check_str_, check_c_, check_arr_num_);
	ft_error_all_free(check_str_, check_c_, check_arr_num_);
	return ;
}

// int main(void){
// 	char *argv[3] = {"3 +6 2 -5 1 +7 -4 10", "9 -12 +11  15 8 14 +13 2147483647","2147483646 -2147483648 -2147483647 0"};
// 	// char *str[3] = {""};
// 	int argc = 4;
	
// 	for(int i = 0; i < argc - 1; i++) {
// 		ft_printf("str[%d] = %s\n", i, argv[i]);
// 	}
// 	//TODO:エラーの処理の戻り値はint*のため、構造体に格納し、座標圧縮へ行く
// 	ft_iserror(argc, argv);
// 	return (0);
// }

// int main(void){
//	 char *str = {"3 +6 2 -5 1 +7 -4 10 9 -12 +11  15 8 14 +13 2147483647 2147483646 -2147483648 -2147483647 0"};
//	 char **check_c_ = ft_split(str, ' ');

//	 ft_printf("str = %s\n", str);
//	 // if (ft_iserror(str))
//	 if (ft_iserror(str))
//	 {
//		 ft_printf("error\n");
//		 return (0);
//	 }
//	 return (0);
// }