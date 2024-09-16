#include "../include/so_long.h"

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

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

//int close(int keycode, t_vars *vars)
//{
//    if (keycode == 53)
//    {
//        mlx_destroy_window(vars->mlx, vars->win);
//        exit(0);
//    }
//    return (0);
//}
//
//int close_window(t_vars *vars)
//{
//    (void)vars;
//    exit(0);
//}

void    get_map(t_map_info *map, char *file_path)
{
    int fd;
    char *temp;
    int i;

    i = 0;
    map->height = 0;
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        error_call(MAP_ERROR);
    while (1)
    {
        temp = get_next_line(fd);
        if (!temp)
            break;
        map->height++;
        map->width = ft_strlen(temp) - 1;
        free(temp);
    }
    close(fd);
    free(temp);
    map->data = (char **)malloc(sizeof(char *) * (map->height + 1));
    fd = open(file_path, O_RDONLY);
    // 長方形チェックとマップの読み取り
    while (1)
    {
        map->data[i] = get_next_line(fd);
        if (!map->data[i])
            break ;
        if (map->width != ft_strlen(map->data[i]) - 1)
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
//    t_vars vars;
//    char *img;
//    char *relative_path;
//    relative_path = strdup("./map/map1.ber");
//    int img_width;
//    int img_height;
    t_map_info map;
    int i;

    if (argc != 2)
        error_call(MAP_DOES_NOT_EXIST);
    else
    {

        i = 0;
        get_map(&map, argv[1]);
        while (map.data[i])
        {
            printf("%zu %s", ft_strlen(map.data[i]), map.data[i]);
            i++;
        }
        printf("\n");
        printf("width:%zu height:%zu\n", map.width, map.height);
        i = 0;
        while (map.data[i])
        {
            free(map.data[i]);
            i++;
        }
        free(map.data);
//        vars.mlx = mlx_init();
//        vars.win = mlx_new_window(vars.mlx, 1000, 650, "Hello world!");
//        img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
//        mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
//        mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//        mlx_hook(vars.win, 17, 1L<<17, close_window, &vars);
//        mlx_loop(vars.mlx);
    }
}
