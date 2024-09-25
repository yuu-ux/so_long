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
    int player_count;
    int end_count;
    int item_count;
    int width;
    int height;
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
} t_map_info;

// エラーハンドリング
#define MAP_DOES_NOT_EXIST 1
#define FUNCTION_ERROR 2
#define MAP_ERROR 3

char *get_next_line(int fd);
void    check_wall(t_map_info *map, int i);
void    check_duplicate(t_map_info *map);
void    check_error(t_map_info *map);
void    error_call(int error_num);
void    get_map(t_map_info *map, char *file_path);
char *ft_chomp (char *str);
int isValid(t_map_info* map, int** visited, int x, int y);
int dfs(t_map_info* map, int** visited, int x, int y);
void	check_wall(t_map_info *map, int i);
void	check_duplicate(t_map_info *map);
void	check_error(t_map_info *map);
void    drawing_map(t_map_info *map);
int    move_player(int keycode, t_map_info *map);
void    operation(t_map_info *map);
