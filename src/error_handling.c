/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:45:39 by yehara            #+#    #+#             */
/*   Updated: 2024/10/06 20:17:26 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_map_info *map, t_stack *stack, int **visited)
{
	t_info	current_pos;
	int		item_count;

	item_count = map->item_count;
	update_current_position(*map, &current_pos, map->player_x, map->player_y);
	push(stack, current_pos);
	while (stack->len > 0)
	{
		current_pos = pop(stack);
		if (current_pos.data == 'E')
		{
			if (!map->item_count)
			{
				map->item_count = item_count;
				return (0);
			}
			continue ;
		}
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

	i = 0;
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
		all_free(NULL, visited, stack, map->height);
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
		error_call(map, NULL, NULL, MAP_ERROR);
}

void	check_error(t_map_info *map)
{
	check_wall(*map);
	check_duplicate(map);
	is_goalable(map);
}
