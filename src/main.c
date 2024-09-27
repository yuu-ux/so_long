#include "so_long.h"

void    error_call(int error_num)
{
    ft_printf("Error\n");
    if (error_num == MAP_DOES_NOT_EXIST)
        ft_printf("map does not exist\n");
    else if (error_num == FUNCTION_ERROR)
        ft_printf("function error\n");
    else if (error_num == MAP_ERROR)
        ft_printf("map error\n");
    exit(1);
}



void    get_map(t_map_info *map, char *file_path)
{
    int fd;
    char *temp;
    int i;

    i = 0;
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        error_call(MAP_ERROR);
    while (1)
    {
        temp = get_next_line(fd);
        if (!temp)
            break;
        map->height++;
        map->width = ft_strlen(ft_chomp(temp));
        free(temp);
    }
    close(fd);
    free(temp);
    map->data = (char **)malloc(sizeof(char *) * (map->height + 1));
    fd = open(file_path, O_RDONLY);
    // 長方形チェックとマップの読み取り
    while (1)
    {
        map->data[i] = ft_chomp(get_next_line(fd));
        if (!(map->data[i]))
            break ;
        if (map->width != ft_strlen(map->data[i]))
            error_call(MAP_ERROR);
        i++;
    }
    close(fd);
    // 正方形チェック
    if (map->height == map->width)
        error_call(MAP_ERROR);
}


int	main(int argc, char **argv)
{
    if (argc != 2)
        error_call(MAP_DOES_NOT_EXIST);
    else
    {
        t_map_info map = {0};
        get_map(&map, argv[1]);
        map.mlx = mlx_init();
        map.win = mlx_new_window(map.mlx, map.width * PIXEL, map.height * PIXEL, "title");
        map.player_x = 1;
        map.player_y = 3;
        check_error(&map);
        drawing_map(&map);
        mlx_hook(map.win, 2, 1L<<0, key_input_event, &map);
        mlx_hook(map.win, 17, 1L<<17, close_window, &map);
        mlx_loop(map.mlx);
    }
}
