SO_LONG = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBMLX = libmlx

FILES = main.c error_handling.c utils.c render_map.c event_functions.c error_handling_utils.c
LIBFT = ./lib/libft
SOURCE = $(addprefix ./src/, $(FILES))
all: $(SO_LONG)

$(SO_LONG): $(SOURCE)
	make -C $(LIBMLX)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -I include $^ -o $@ libmlx/libmlx_Linux.a libmlx/libmlx.a -lm -lXext -lX11 lib/libft/libft.a

clean:
	make clean -C $(LIBMLX) 
	make clean -C $(LIBFT) 
	rm -f *.o

fclean: clean
	make clean -C $(LIBMLX)
	make fclean -C $(LIBFT)
	rm -f $(SO_LONG)

re: fclean all

.PHONY: all clean fclean re
