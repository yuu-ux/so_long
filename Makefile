SO_LONG = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBMLX = libmlx

SOURCE = ./src/main.c ./src/error_handling.c ./src/utils.c
GET_NEXT_LINE_SOURCE = ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c
PRINTF = ./lib/printf
GET_NEXT_LINE = ./lib/get_next_line

all: $(SO_LONG)

$(SO_LONG): $(SOURCE)
	make -C $(LIBMLX)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -g $^ $(GET_NEXT_LINE_SOURCE) -o $@ -Llibmlx -lmlx -framework OpenGL -framework AppKit -L./lib/printf -lftprintf

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
