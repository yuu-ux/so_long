SO_LONG = so_long

CC = cc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror #
LIBMLX = libmlx

FILES = main.c error_handling.c utils.c drawing.c
GET_NEXT_LINE_SOURCE = ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c
PRINTF = ./lib/printf
GET_NEXT_LINE = ./lib/get_next_line
SOURCE = $(addprefix ./src/, $(FILES))
all: $(SO_LONG)

$(SO_LONG): $(SOURCE)
	make -C $(LIBMLX)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -I include $^ $(GET_NEXT_LINE_SOURCE) -o $@ -Llibmlx -lmlx -framework OpenGL -framework AppKit -L./lib/printf -lftprintf

clean:
	make -C $(LIBMLX) clean
	make -C $(PRINTF) clean
	rm -f *.o

fclean: clean
	make -C $(LIBMLX) fclean
	make -C $(PRINTF) fclean
	rm -f $(SO_LONG)

re: fclean all

.PHONY: all clean fclean re
