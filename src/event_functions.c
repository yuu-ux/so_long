/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:13:35 by yehara            #+#    #+#             */
/*   Updated: 2024/10/06 22:26:34 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_map_info *map, char next_elem)
{
	if (next_elem == 'E')
	{
		if (map->item_count)
			return (1);
		else
		{
			ft_printf("ゴール!\n");
			all_free(map, NULL, NULL, map->height);
			exit(0);
		}
	}
	if (next_elem != '1')
	{
		if (next_elem == 'C')
			map->item_count--;
		return (1);
	}
	return (0);
}

void	update_map(t_map_info *map, int last_x, int last_y)
{
	if (last_x == map->player_x && last_y == map->player_y)
		return ;
	else
	{
		map->data[last_y][last_x] = '0';
		if (last_x == map->end_x && last_y == map->end_y)
			map->data[last_y][last_x] = 'E';
		map->data[map->player_y][map->player_x] = 'P';
		map->move_count++;
		ft_printf("move_count -> %d\n", map->move_count);
		render_map(map);
	}
}

int	close_window(t_map_info *map)
{
	all_free(map, NULL, NULL, map->height);
	exit(0);
}

void	set_player(t_map_info *map, int x, int y)
{
	map->player_x = x;
	map->player_y = y;
}

int	key_input_event(int keycode, void *map_)
{
	int			x;
	int			y;
	t_map_info	*map;

	map = map_;
	x = map->player_x;
	y = map->player_y;
	if (keycode == KEY_ESC)
	{
		all_free(map, NULL, NULL, map->height);
		exit(0);
	}
	else if (keycode == KEY_A)
		map->player_x -= 1;
	else if (keycode == KEY_D)
		map->player_x += 1;
	else if (keycode == KEY_S)
		map->player_y += 1;
	else if (keycode == KEY_W)
		map->player_y -= 1;
	if (check_move(map, map->data[map->player_y][map->player_x]))
		update_map(map, x, y);
	else
		set_player(map, x, y);
	return (0);
}
