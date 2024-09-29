#include "so_long.h"

int isValid(t_map_info *map, int **visited, int x, int y)
{
    if (x >= 0 && x < map->width && y >= 0 && y < map->height
        && map->data[y][x] != '1' && !visited[y][x])
	{
		if (map->data[y][x] == 'C')
			map->item_count--;
		return 1;
	}
	return 0;
}


void	init_directions(int directions[4][2])
{
	// 上に移動する
	directions[0][0] = 0;  // x方向の変化なし
	directions[0][1] = -1; // y方向に-1（上へ移動）
	// 下に移動する
	directions[1][0] = 0; // x方向の変化なし
	directions[1][1] = 1; // y方向に+1（下へ移動）
	// 左に移動する
	directions[2][0] = -1; // x方向に-1（左へ移動）
	directions[2][1] = 0;  // y方向の変化なし
	// 右に移動する
	directions[3][0] = 1; // x方向に+1（右へ移動）
	directions[3][1] = 0; // y方向の変化なし
}

void	update_current_position(t_map_info map, t_info *current_pos, int x,
		int y)
{
	current_pos->data = map.data[y][x];
	current_pos->x = x;
	current_pos->y = y;
}

void	is_goalable(t_map_info *map)
{
	int		**visited;
	t_stack	stack;
	t_info	current_pos;
	t_info  new_pos;
	int		directions[4][2];
	int		i;
	int		item_count;
	int		new_x;
	int		new_y;

	i = 0;
	item_count = map->item_count;
	ft_memset(&stack, 0, sizeof(t_stack));
	init_directions(directions);
	visited = (int **)malloc(map->height * sizeof(int *));
	while (i < map->height)
		visited[i++] = (int *)ft_calloc(map->width, sizeof(int));
	update_current_position(*map, &current_pos, map->player_x, map->player_y);
	push(&stack, current_pos);
	while (stack.len > 0)
	{
		current_pos = pop(&stack);
		if (current_pos.data == 'E')
		{
			if (!map->item_count)
			{
				map->item_count = item_count;
				return ;
			}
			continue ;
		}
		visited[current_pos.y][current_pos.x] = 1;
		i = 0;
		while (i < 4)
		{
			new_x = current_pos.x + directions[i][0];
			new_y = current_pos.y + directions[i][1];
			if (isValid(map, visited, new_x, new_y))
			{
				update_current_position(*map, &new_pos, new_x, new_y);
				push(&stack, new_pos);
			}
			i++;
		}
	}
	error_call(map, MAP_ERROR);
}

void	check_wall(t_map_info map)
{
	int	i;
	int	j;

	i = 0;
	while (map.data[i])
	{
		if (map.data[i][0] != '1' || map.data[i][map.width - 1] != '1')
			error_call(&map, MAP_ERROR);
		if (i == 0 || i == map.height - 1)
		{
			j = 0;
			while (map.data[i][j])
			{
				if (map.data[i][j] != '1')
					error_call(&map, MAP_ERROR);
				j++;
			}
		}
		i++;
	}
}

void	check_duplicate(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'C')
				map->item_count++;
			else if (map->data[i][j] == 'P')
			{
				map->player_count++;
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->data[i][j] == 'E')
				map->end_count++;
			j++;
		}
		i++;
	}
	if (map->player_count != 1 || map->end_count != 1 || map->item_count == 0)
		error_call(map, MAP_ERROR);
}

void	check_error(t_map_info *map)
{
	check_wall(*map);
	check_duplicate(map);
	printf("test\n");
	is_goalable(map);
}
