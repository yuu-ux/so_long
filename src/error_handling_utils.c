/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:08:24 by yehara            #+#    #+#             */
/*   Updated: 2024/10/01 19:28:37 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_free(t_map_info *map, int **visited)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map->data[i])
			free(map->data[i++]);
		free(map->data);
	}
	if (visited)
	{
		i = 0;
		while (i < map->height)
			free(visited[i++]);
		free(visited);
	}
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

int	is_valid(t_map_info *map, int **visited, int x, int y)
{
	if (x >= 0 && x < map->width && y >= 0 && y < map->height
		&& map->data[y][x] != '1' && !visited[y][x])
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

void	explore_map(t_map_info *map, t_stack *stack, t_info current_pos,
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
		if (is_valid(map, visited, new_x, new_y))
		{
			update_current_position(*map, &new_pos, new_x, new_y);
			push(stack, new_pos);
		}
		i++;
	}
}
