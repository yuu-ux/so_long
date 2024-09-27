/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:21:20 by yehara            #+#    #+#             */
/*   Updated: 2024/09/28 04:39:43 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_call(t_map_info *map, int error_num)
{
	all_free(map);
	ft_printf("Error\n");
	if (error_num == MAP_DOES_NOT_EXIST)
		ft_printf("map does not exist\n");
	else if (error_num == FUNCTION_ERROR)
		ft_printf("function error\n");
	else if (error_num == MAP_ERROR)
		ft_printf("map error\n");
	exit(1);
}

void	get_map(t_map_info *map, char *file_path)
{
	int	fd;
	int	i;

	i = 0;
	map_init(map, file_path);
	map->data = (char **)ft_calloc(sizeof(char *), (map->height + 1));
	fd = open(file_path, O_RDONLY);
	while (1)
	{
		map->data[i] = ft_chomp(get_next_line(fd));
		if (!(map->data[i]))
			break ;
		if (map->width != ft_strlen(map->data[i]))
			error_call(map, MAP_ERROR);
		i++;
	}
	close(fd);
	if (map->height == map->width)
		error_call(map, MAP_ERROR);
}

int	main(int argc, char **argv)
{
	t_map_info	map;

	ft_memset(&map, 0, sizeof(map));
	if (argc != 2)
		error_call(&map, MAP_DOES_NOT_EXIST);
	else
	{
		get_map(&map, argv[1]);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, map.width * PIXEL, map.height * PIXEL,
				"Game");
		map.player_x = 1;
		map.player_y = 3;
		check_error(&map);
		drawing_map(&map);
		mlx_hook(map.win, 2, 1L << 0, key_input_event, &map);
		mlx_hook(map.win, 17, 1L << 17, close_window, &map);
		mlx_loop(map.mlx);
	}
}
