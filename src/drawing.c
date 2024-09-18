#include "../include/so_long.h"

void    draw_wall(t_vars *vars, int x, int y)
{
    char *img;
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(vars->mlx, "./image/wall.xpm", &img_width, &img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, img, x * img_height, y * img_width);
}

void    draw_player(t_vars *vars, int x, int y)
{
    char *img;
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(vars->mlx, "./image/player.xpm", &img_width, &img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, img, x * img_height, y * img_width);
}

void    draw_floor(t_vars *vars, int x, int y)
{
    char *img;
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(vars->mlx, "./image/floor.xpm", &img_width, &img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, img, x * img_height, y * img_width);
}

void    draw_item(t_vars *vars, int x, int y)
{
    char *img;
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(vars->mlx, "./image/item.xpm", &img_width, &img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, img, x * img_height, y * img_width);
}

//void    draw_end(t_vars *vars, int x, int y)
//{
//    char *img;
//    int img_width;
//    int img_height;
//
//    img = mlx_xpm_file_to_image(vars->mlx, "./image/end.xpm", &img_width, &img_height);
//    mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
//}

void    drawing_map(t_map_info *map, t_vars *vars)
{
    int i;
    int j;

    i = 0;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1000, 650, "Hello world!");

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->data[i][j] == 'P')
                draw_player(vars, j, i);
            else if (map->data[i][j] == '1')
                draw_wall(vars, j, i);
            else if (map->data[i][j] == '0')
                draw_floor(vars, j, i);
            else if (map->data[i][j] == 'C')
                draw_item(vars, j, i);
            j++;
        }
        i++;
    }
//    draw_end(vars, 0, 4);
}
