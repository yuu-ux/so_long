SO_LONG = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBMLX = libmlx

FILES = main.c error_handling.c utils.c drawing.c event_functions.c
GET_NEXT_LINE_SOURCE = ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c
PRINTF = ./lib/printf
GET_NEXT_LINE = ./lib/get_next_line
SOURCE = $(addprefix ./src/, $(FILES))
all: $(SO_LONG)

$(SO_LONG): $(SOURCE)
	make -C $(LIBMLX)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -I include $^ $(GET_NEXT_LINE_SOURCE) -o $@ libmlx/libmlx_Linux.a libmlx/libmlx.a -lm -lXext -lX11 -L./lib/printf -lftprintf

clean:
	make clean -C $(LIBMLX) 
	make clean -C $(PRINTF) 
	rm -f *.o

fclean: clean
	make clean -C $(LIBMLX)
	make fclean -C $(PRINTF)
	rm -f $(SO_LONG)

re: fclean all

.PHONY: all clean fclean re
