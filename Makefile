# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 18:42:11 by yshimoma          #+#    #+#              #
#    Updated: 2023/04/18 20:10:30 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_DIR = ./src
SRCS = main.c error.c error_utils.c quick_sort.c utils.c\
		swap.c push.c rotate.c reverse_rotate.c stack.c\
		put_error.c long_sort.c long_sort_utils.c min_sort.c\
		min_sort_utils.c
vpath %.c ${SRCS_DIR}
OBJ_DIR = ./obj
OBJS = ${addprefix $(OBJ_DIR)/, $(SRCS:.c=.o)}
INCLUDE = ./header
CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs
RM = rm -rf

ifdef DEBUG_FLAG
CFLAGS += -g -D COMP_DEF_FLAG=2
endif

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${CFLAGS} -I${INCLUDE} libft/libft.a ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ./obj
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

debug:
	@make DEBUG_FLAG=2

.PHONY: all clean fclean re debug
