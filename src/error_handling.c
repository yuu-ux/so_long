#include "../include/so_long.h"

void	check_wall(t_map_info *map, int i)
{
	int	j;

	j = 0;
	if (i == 0 || i == map->height - 1)
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] != '1')
				error_call(MAP_ERROR);
			j++;
		}
	}
	return ;
}

void	check_duplicate(t_map_info *map)
{
	printf("player:%d end:%d item:%d\n", map->player_count, map->end_count,
		map->item_count);
	if (map->player_count != 1 || map->end_count != 1 || map->item_count == 0)
		error_call(MAP_ERROR);
}

void	check_error(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		if (map->data[i][j] != '1')
			error_call(MAP_ERROR);
		else
		{
			check_wall(map, i);
			while (map->data[i][j])
			{
				if (map->data[i][j] == 'C')
					map->item_count++;
				else if (map->data[i][j] == 'P')
					map->player_count++;
				else if (map->data[i][j] == 'E')
					map->end_count++;
				else if (!(map->data[i][j + 1]))
				{
					if (map->data[i][j] != '1')
						error_call(MAP_ERROR);
				}
				j++;
			}
		}
		i++;
	}
	check_duplicate(map);
}
