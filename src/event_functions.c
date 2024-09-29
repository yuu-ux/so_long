#include "so_long.h"

void    update_map(t_map_info *map, int x, int y)
{
    map->data[y][x] = '0';
    map->data[map->player_y][map->player_x] = 'P';
    drawing_map(map);
}

int    close_window(t_map_info *map)
{
    int i;

    i = 0;
    while (map->data[i])
    {
        free(map->data[i]);
    }
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
    if (keycode == KEY_ESC)
    {
        all_free(map);
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