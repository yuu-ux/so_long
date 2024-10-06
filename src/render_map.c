/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:39:22 by yehara            #+#    #+#             */
/*   Updated: 2024/10/06 16:26:40 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map_info *map)
{
	size_t		y;
	size_t		x;
	char	*path;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'P')
				path = "./image/player.xpm";
			else if (map->data[y][x] == '1')
				path = "./image/wall.xpm";
			else if (map->data[y][x] == '0')
				path = "./image/floor.xpm";
			else if (map->data[y][x] == 'C')
				path = "./image/item.xpm";
			else if (map->data[y][x] == 'E')
				path = "./image/end.xpm";
			drawing_map(map, path, y, x);
			x++;
		}
		y++;
	}
}

void	drawing_map(t_map_info *map, char *path, int x, int y)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_width,
			&map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img, y * PIXEL, x * PIXEL);
	mlx_destroy_image(map->mlx, map->img);
}
