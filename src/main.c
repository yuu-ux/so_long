#include "../libmlx/mlx.h"
#include "../include/so_long.h"
#include <stdlib.h>
#include <string.h>

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int close(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int close_window(t_vars *vars)
{
    (void)vars;
    exit(0);
}

int	main(void)
{
    t_vars vars;
    char *img;
    char *relative_path;
    relative_path = strdup("./image/11zon_floor.xpm");
    int img_width;
    int img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 650, "Hello world!");
    img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_hook(vars.win, 17, 1L<<17, close_window, &vars);
	mlx_loop(vars.mlx);
}
