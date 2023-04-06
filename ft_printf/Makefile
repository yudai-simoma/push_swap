# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:15:53 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/22 20:23:04 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_itoa.c ft_u_itoa.c ft_16_itoa_upper.c \
	ft_16_itoa_lower.c ft_16_address_itoa.c ft_putstr_fd.c ft_calloc.c ft_memset.c \
	ft_strlen.c ft_size_t_itoa.c
OBJS = ${SRCS:.c=.o}
INCLUDE = ../header
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

.c.o:
	${CC} -I${INCLUDE} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re