# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 13:31:55 by yehara            #+#    #+#              #
#    Updated: 2024/05/12 15:56:20 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_bzero.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

BFLAGS = 0
ifeq ($(BFLAGS), 1)
	SRURCES = $(SRCS) $(SRCSB)
else
	SRURCES = $(SRCS)
endif
OBJS = $(SRURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@$(MAKE) all BFLAGS=1
	
clean:
	$(RM) $(SRCS:.c=.o) $(SRCSB:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re