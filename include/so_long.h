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
    int player_x;
    int player_y;
    int move_count;
} t_map_info;

typedef struct s_info
{
    char data;
    int x;
    int y;
} t_info;

typedef struct s_stack 
{
    t_info *data;
    size_t len;
    size_t size;
} t_stack;

//enum e_map {
//    FLOOR;
//   ITEM;
//   WALL;
//   PLYAER;
//    END;
//}
// エラーハンドリング
#define MAP_DOES_NOT_EXIST 1
#define FUNCTION_ERROR 2
#define MAP_ERROR 3
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_W 119
#define KEY_ESC 65307
#define PIXEL 50

// エラーハンドリング
void    all_free(t_map_info *map, int **visited);
void    error_call(t_map_info *map, int error_num);
char *get_next_line(int fd);
void    check_wall(t_map_info map);
void    check_duplicate(t_map_info *map);
void    check_error(t_map_info *map);
void    get_map(t_map_info *map, char *file_path);
void    map_init(t_map_info *map, char *file_path);
char *ft_chomp (char *str);
int isValid(t_map_info* map, int** visited, int x, int y);
int    dfs(t_map_info *map, t_stack stack, int **visited, int directions[4][2]);
void	check_duplicate(t_map_info *map);
void	check_error(t_map_info *map);
void    drawing_map(t_map_info *map);
void    update_map(t_map_info *map, int x, int y);
int    close_window(t_map_info *map);
void    set_player(t_map_info *map, int x, int y);
int    key_input_event(int keycode, void *map_);
int    check_move(t_map_info *map, char next_elem);
void    map_init(t_map_info *map, char *file_path);
t_info	pop(t_stack *stack);
int	push(t_stack *stack, t_info c);