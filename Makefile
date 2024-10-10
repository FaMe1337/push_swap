# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famendes <famendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 12:18:35 by famendes          #+#    #+#              #
#    Updated: 2024/10/10 12:37:01 by famendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= big_sort_utils.c big_sort.c init_node_a.c init_node_b.c main_utils.c main.c parsing_utils.c parsing.c push.c reverse_rotate.c rotate.c sorting.c stack_manipulation.c swap.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= push_swap

CC		= cc -Wall -Wextra -Werror -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -ILibft -Iprintf -c $< -o $@

${NAME}:		${OBJS}
		@make -C Libft
		@make -C printf
		${CC} ${CFLAGS} $^ -LLibft -lft -Lprintf -lftprintf -o ${NAME}

libft:
		make -C Libft

printf:
		make -C printf

clean:
			make clean -C Libft
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			make fclean -C Libft
			make fclean -C printf
			${RM} ${NAME}

re:			fclean all

.PHONY:		Libft printf
