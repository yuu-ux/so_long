/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:04:18 by yehara            #+#    #+#             */
/*   Updated: 2024/10/06 22:23:48 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../libmlx/mlx.h"

typedef struct s_map_info
{
	char	**data;
	int		player_count;
	int		end_count;
	int		item_count;
	size_t	width;
	size_t	height;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		end_x;
	int		end_y;
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

# define MAP_DOES_NOT_EXIST 1
# define FUNCTION_ERROR 2
# define MAP_ERROR 3
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define PIXEL 50

void		error_call(t_map_info *map, int **visited, t_stack *stack,
				int error_num);
void		get_map(t_map_info *map, char *file_path);
void		check_error(t_map_info *map);
int			dfs(t_map_info *map, t_stack *stack, int **visited);
void		is_goalable(t_map_info *map);
void		check_wall(t_map_info map);
void		check_duplicate(t_map_info *map);
int			is_valid(t_map_info *map, int **visited, size_t x, size_t y);
void		init_directions(int directions[4][2]);
void		update_current_position(t_map_info map, t_info *current_pos, int x,
				int y);
void		explore_map(t_map_info *map, t_stack *stack, t_info current_pos,
				int **visited);
void		all_free(t_map_info *map, int **visited, t_stack *stack,
				size_t size);
void		render_map(t_map_info *map);
void		drawing_map(t_map_info *map, char *path, int x, int y);
char		*ft_chomp(char *str);
void		map_init(t_map_info *map, char *file_path);
t_info		pop(t_stack *stack);
int			push(t_stack *stack, t_info c);
int			key_input_event(int keycode, void *map_);
void		set_player(t_map_info *map, int x, int y);
int			close_window(t_map_info *map);
void		update_map(t_map_info *map, int x, int y);
int			check_move(t_map_info *map, char next_elem);
void		set_and_count_end(t_map_info *map, int x, int y);

#endif
