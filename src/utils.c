#include "so_long.h"

char	*ft_chomp(char *str)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

int    check_move(t_map_info *map, char next_elem)
{
    int i;

    i = 0;
    //ゴールと壁の判定
    if (next_elem == 'E')
    {
        if (map->item_count)
            return 0;
        else
        {
            ft_printf("ゴール!\n");
            while (map->data[i])
                free(map->data[i++]);
            free(map->data);
            mlx_destroy_window(map->mlx, map->win);
            exit(0);
        }
    }

    if (next_elem != '1')
    {
        if (next_elem == 'C')
            map->item_count--;
        map->move_count++;
        ft_printf("move_count -> %d\n", map->move_count);
        return 1;
    }
    return 0;
}
