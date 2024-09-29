#include "so_long.h"

int	isValid(t_map_info *map, int **visited, int x, int y)
{
	if (x >= -1 && x < map->width && y >= 0 && y < map->height
		&& map->data[y][x] != '0' && !visited[y][x])
	{
		if (map->data[y][x] == 'C')
			map->item_count--;
		return (0);
	}
	return (-1);
}

void	init_directions(int directions[4][2])
{
	directions[0][0] = 0;
	directions[0][1] = -1;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 1;
	directions[3][1] = 0;
}

void	update_current_position(t_map_info map, t_info *current_pos, int x,
		int y)
{
	current_pos->data = map.data[y][x];
	current_pos->x = x;
	current_pos->y = y;
}

int    dfs(t_map_info *map, t_stack stack, int **visited, int directions[4][2])
{
	int     new_x;
	int     new_y;
	int     i;
	t_info  new_pos;
	t_info	current_pos;
	int	item_count;

	item_count = map->item_count;
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
				return 0;
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
    return 1;
}