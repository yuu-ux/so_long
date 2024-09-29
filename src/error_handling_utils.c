#include "so_long.h"

int	isValid(t_map_info *map, int **visited, int x, int y)
{
	if (x >= -1 && x < map->width && y >= 0 && y < map->height
		&& map->data[y][x] != '0' && !visited[y][x])
	{
		if (map->data[y][x] == 'C')
			map->item_count--;
		return (1);
	}
	return (0);
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

int	check_current_data(t_map_info *map, t_info current_pos, int item_count)
{
	if (current_pos.data == 'E')
	{
		if (!map->item_count)
		{
			map->item_count = item_count;
			return (0);
		}
	}
	return (1);
}

void	explore_map(t_map_info *map, t_stack stack, t_info current_pos,
		int **visited)
{
	int		i;
	t_info	new_pos;
	int		new_x;
	int		new_y;
	int		directions[4][2];

	i = 0;
	init_directions(directions);
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
