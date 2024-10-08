/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:45:39 by yehara            #+#    #+#             */
/*   Updated: 2024/10/08 18:03:54 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_map_info *map, t_stack *stack, int **visited)
{
	t_info	current_pos;

	update_current_position(*map, &current_pos, map->player_x, map->player_y);
	if (push(stack, current_pos) == -1)
		error_call(map, visited, stack, FUNCTION_ERROR);
	while (stack->len > 0)
	{
		current_pos = pop(stack);
		check_invalid_value(map, stack, visited, current_pos);
		if (current_pos.data == 'E')
		{
			if (!map->item_count)
				return (0);
		}
		if (current_pos.x == map->end_x && current_pos.y == map->end_y)
			visited[current_pos.y][current_pos.x] = 0;
		else
			visited[current_pos.y][current_pos.x] = 1;
		explore_map(map, stack, current_pos, visited);
	}
	return (1);
}

void	is_goalable(t_map_info *map)
{
	int		**visited;
	t_stack	*stack;
	size_t	i;
	int		item_count;

	i = 0;
	item_count = map->item_count;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_call(map, NULL, NULL, FUNCTION_ERROR);
	ft_memset(stack, 0, sizeof(t_stack));
	visited = (int **)malloc(map->height * sizeof(int *));
	if (!visited)
		error_call(map, NULL, NULL, FUNCTION_ERROR);
	while (i < map->height)
		visited[i++] = (int *)ft_calloc(map->width, sizeof(int));
	if (dfs(map, stack, visited))
		error_call(map, visited, stack, MAP_ERROR);
	else
	{
		all_free(NULL, visited, stack, map->height);
		map->item_count = item_count;
	}
}

void	check_wall(t_map_info map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map.data[i])
	{
		if (map.data[i][0] != '1' || map.data[i][map.width - 1] != '1')
			error_call(&map, NULL, NULL, MAP_ERROR);
		if (i == 0 || i == map.height - 1)
		{
			j = 0;
			while (map.data[i][j])
			{
				if (map.data[i][j] != '1')
					error_call(&map, NULL, NULL, MAP_ERROR);
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
				set_player(map, j, i);
			}
			else if (map->data[i][j] == 'E')
				set_and_count_end(map, j, i);
			j++;
		}
		i++;
	}
	if (map->player_count != 1 || map->end_count != 1 || map->item_count == 0)
		error_call(map, NULL, NULL, MAP_ERROR);
}

void	check_error(t_map_info *map)
{
	check_wall(*map);
	check_duplicate(map);
	is_goalable(map);
}
