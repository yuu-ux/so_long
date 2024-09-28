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

void    map_init(t_map_info *map, char *file_path)
{
    int fd;
    char *temp;
    
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        error_call(map, MAP_ERROR);
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
}

void    all_free(t_map_info *map)
{
    int i;

    if (map->data)
    {
        i = 0;
        while (map->data[i])
            free(map->data[i++]);
        free(map->data);
    }

    if (map->win || map->mlx)
        mlx_destroy_window(map->mlx, map->win);
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

t_info	pop(t_stack *stack)
{
    t_info res;

    res = stack->data[stack->len-1];
    stack->data[stack->len-1].data = -100;
    stack->len--;
    return res;
}

int	push(t_stack *stack, t_info c)
{
    t_info	*new_data;
    size_t	size;

    if (stack->data == NULL || stack->len + 1 > stack->size)
    {
        if (stack->size > 0)
            size = stack->size * 2;
        else
            size = 2;
        new_data = malloc(size * sizeof(t_info));
        if (!new_data)
            return (-1);
        ft_memcpy(new_data, stack->data, sizeof(t_info) * stack->len);
        free(stack->data);
        stack->data = new_data;
        stack->size = size;
    }
    stack->data[stack->len++] = c;
    return (0);
}