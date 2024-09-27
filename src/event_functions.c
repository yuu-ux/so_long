#include "so_long.h"

void    update_map(t_map_info *map, int x, int y)
{
    map->data[y][x] = '0';
    map->data[map->player_y][map->player_x] = 'P';
    drawing_map(map);
}

int    close_window(t_map_info *map)
{
    free(map->data);
    exit(0);
}

void    set_player(t_map_info *map, int x, int y)
{
    map->player_x = x;
    map->player_y = y;
}

int    key_input_event(int keycode, void *map_)
{
    int x;
    int y;
    t_map_info *map;

    map = map_;
    x = map->player_x;
    y = map->player_y;
    if (keycode == 53)
    {
        mlx_destroy_window(map->mlx, map->win);
        exit(0);
    }
    else if (keycode == 0)
        map->player_x -= 1;
    else if (keycode == 2)
        map->player_x += 1;
    else if (keycode == 1)
        map->player_y += 1;
    else if (keycode == 13)
        map->player_y -= 1;
    if (check_move(map, map->data[map->player_y][map->player_x]))
        update_map(map, x, y);
    else
        set_player(map, x, y);
    return (0);
}
