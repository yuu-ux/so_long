#include "../include/so_long.h"

int isValid(t_map_info* map, int** visited, int x, int y)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height &&
            map->data[y][x] != '1' && !visited[y][x]);
}

// 深さ優先探索アルゴリズム
int dfs(t_map_info* map, int** visited, int x, int y)
{
    // ゴールに到達した場合
    if (map->data[y][x] == 'E') {
        return 1;
    }

    // 訪問済みに設定
    visited[y][x] = 1;

    // 移動可能な方向（上、下、左、右）
    int rowNum[] = {-1, 1, 0, 0};
    int colNum[] = {0, 0, -1, 1};

    // 隣接するセルを探索
    for (int i = 0; i < 4; i++) {
        int newX = x + colNum[i];
        int newY = y + rowNum[i];

        if (isValid(map, visited, newX, newY)) {
            if (dfs(map, visited, newX, newY))
                return 1;
        }
    }

    return 0;
}

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
	int** visited = (int**)malloc(map->height * sizeof(int*));
    for (int i = 0; i < map->height; i++) {
        visited[i] = (int*)calloc(map->width, sizeof(int));
    }
	if (!(dfs(map, visited, 1, 3)))
        error_call(MAP_ERROR);
}
