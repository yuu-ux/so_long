/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:08:24 by yehara            #+#    #+#             */
/*   Updated: 2024/10/06 23:31:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_invalid_value(t_map_info *map, t_stack *stack, int **visited,
		t_info current_pos)
{
	if (current_pos.data != 'C' && current_pos.data != '0'
		&& current_pos.data != 'E' && current_pos.data != 'P')
		error_call(map, visited, stack, MAP_ERROR);
}

int	is_valid(t_map_info *map, int **visited, size_t x, size_t y)
{
	if (map->data[y][x] != '1' && !visited[y][x])
	{
		if (map->data[y][x] == 'C' && map->item_count > 0)
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
			if (push(stack, new_pos) == -1)
				error_call(map, visited, stack, FUNCTION_ERROR);
		}
		i++;
	}
}
