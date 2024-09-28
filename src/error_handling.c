#include "so_long.h"

int isValid(t_map_info* map, int** visited, int x, int y)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height &&
            map->data[y][x] != '1' && !visited[y][x]);
}

int is_goalable(t_map_info *map) {
    int **visited;
	t_stack	stack = {0};
	t_info temp;
	int i;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    visited = (int **)malloc(map->height * sizeof(int *));
    for (int i = 0; i < map->height; i++) visited[i] = (int *)calloc(map->width, sizeof(int));

    temp.data = map->data[map->player_y][map->player_x];
    temp.x = map->player_x; 
    temp.y = map->player_y; 
	push(&stack, temp);

    while (stack.len > 0) {
		temp = pop(&stack);
        if (map->data[temp.y][temp.x] == 'E')
		{
			if (!map->item_count)
				return 1;
			continue;
		}
        visited[temp.y][temp.x] = 1;
      i = 0;  
	  while (i < 4)
	  {
            int newX = temp.x + directions[i][0];
			int newY = temp.y + directions[i][1];

            if (isValid(map, visited, newX, newY)) {
				temp.data = map->data[newY][newX];
				temp.x = newX;
				temp.y = newY;
				push(&stack, temp);
            }
		i++;
	  }
    }
    return 0;
}

void	check_wall(t_map_info *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map->data[i])
	{
		if (map->data[i][0] != 1 || map->data[i][map->width-1] != 1)
			error_call(map, MAP_ERROR);

		if (i == 0 || i == map->height-1)
		{
			while (map->data[i][j])
			{
				if (map->data[i][j] != 1)
					error_call(map, MAP_ERROR);
				j++;
			}
		}
	}
}

void	check_duplicate(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->data[i])
	{
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
	check_wall(map);
	check_duplicate(map);
	is_goalable(map);
}
