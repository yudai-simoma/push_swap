# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 18:42:11 by yshimoma          #+#    #+#              #
#    Updated: 2023/04/06 18:59:01 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_DIR = ./src
SRCS = *.c
vpath %.c ${SRCS_DIR}
OBJ_DIR = ./obj
OBJS = ${addprefix $(OBJ_DIR)/, $(SRCS:.c=.o)}
INCLUDE = ./header
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${MAKE} -C ft_printf
	${CC} -I${INCLUDE} libft/libft.a ft_printf/libftprintf.a ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ./obj
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re