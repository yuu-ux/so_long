#include "so_long.h"

void	is_goalable(t_map_info *map)
{
	int		**visited;
	t_stack	stack;
	int		directions[4][2];
	int		i;

	i = 0;
	ft_memset(&stack, 0, sizeof(t_stack));
	init_directions(directions);
	visited = (int **)malloc(map->height * sizeof(int *));
	while (i < map->height)
		visited[i++] = (int *)ft_calloc(map->width, sizeof(int));
	if (dfs(map, stack, visited, directions))
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
	is_goalable(map);
}
