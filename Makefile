SO_LONG = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = libmlx

SOURCE = src/main.c

all: $(SO_LONG)

$(SO_LONG): $(SOURCE)
	make -C $(LIBMLX)
	$(CC) $(CFLAGS) $^ -o $@ -Llibmlx -lmlx -framework OpenGL -framework AppKit

clean:
	make -C $(LIBMLX) clean
	rm -f *.o

re: clean all

.PHONY: all clean fclean re
