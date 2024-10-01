# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehara <yehara@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 16:35:15 by yehara            #+#    #+#              #
#    Updated: 2024/10/01 20:11:03 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC	= cc
FLAGS	= -Wall -Werror -Wextra
LIBFT	= ./libft/libft.a
SRCS	= ft_printf.c ft_printf_char.c ft_printf_dec.c ft_printf_hex.c ft_printf_ptr.c ft_printf_str.c ft_printf_unsigned_dec.c
OBJS	= ${SRCS:.c=.o}

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	make -C libft
	cp ${LIBFT} ${NAME}
	${AR} rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine *.h

.PHONY: all re clean fclean
