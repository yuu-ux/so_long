// 標準ライブラリ
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/printf/ft_printf.h"
#include "../libmlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 構造体定義
typedef struct s_map_info
{
	char	**data;
	int		player_count;
	int		end_count;
	int		item_count;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		move_count;
}			t_map_info;

typedef struct s_info
{
	char	data;
	int		x;
	int		y;
}			t_info;

typedef struct s_stack
{
	t_info	*data;
	size_t	len;
	size_t	size;
}			t_stack;

// enum e_map {
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

// main.c
void		error_call(t_map_info *map, int **visited, int error_num);
void		get_map(t_map_info *map, char *file_path);

// error_handling.c
void		check_error(t_map_info *map);
int			dfs(t_map_info *map, t_stack *stack, int **visited);
void		is_goalable(t_map_info *map);
void		check_wall(t_map_info map);
void		check_duplicate(t_map_info *map);

// error_handling_utils.c
int			is_valid(t_map_info *map, int **visited, int x, int y);
void		init_directions(int directions[4][2]);
void		update_current_position(t_map_info map, t_info *current_pos, int x,
				int y);
void	explore_map(t_map_info *map, t_stack *stack, t_info current_pos,
		int **visited);
void		all_free(t_map_info *map, int **visited);

// drawing.c
void		drawing_map(t_map_info *map);

// utilis.c
char		*ft_chomp(char *str);
void		map_init(t_map_info *map, char *file_path);
int			check_move(t_map_info *map, char next_elem);
t_info		pop(t_stack *stack);
int			push(t_stack *stack, t_info c);

// event_function.c
int			key_input_event(int keycode, void *map_);
void		set_player(t_map_info *map, int x, int y);
int			close_window(t_map_info *map);
void		update_map(t_map_info *map, int x, int y);

// get_next_line.c
char		*get_next_line(int fd);