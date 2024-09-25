#include "so_long.h"

void    drawing_map(t_map_info *map)
{
    int i;
    int j;
    char *path;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->data[i][j] == 'P')
                path = ft_strdup("./image/player.xpm");
            else if (map->data[i][j] == '1')
                path = ft_strdup("./image/wall.xpm");
            else if (map->data[i][j] == '0')
                path = ft_strdup("./image/floor.xpm");
            else if (map->data[i][j] == 'C')
                path = ft_strdup("./image/item.xpm");
            else if (map->data[i][j] == 'E')
                path = ft_strdup("./image/end.xpm");
            map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_width, &map->img_height);
            mlx_put_image_to_window(map->mlx, map->win, map->img, j * map->img_height, i * map->img_width);
            free(path);
            j++;
        }
        i++;
    }
}
