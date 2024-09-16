// 標準ライブラリ
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "../lib/printf/ft_printf.h"
#include "../libmlx/mlx.h"
#include "../lib/get_next_line/get_next_line.h"

// 構造体定義
typedef struct s_map_info {
    char **data;
    int start_count;
    int end_count;
    int item_count;
    size_t width;
    size_t height;
} t_map_info;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
    void *mlx;
    void *win;
}   t_vars;

// エラーハンドリング
#define MAP_DOES_NOT_EXIST 1
#define FUNCTION_ERROR 2
#define MAP_ERROR 3

char *get_next_line(int fd);
