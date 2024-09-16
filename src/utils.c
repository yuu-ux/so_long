#include "../include/so_long.h"

char *ft_chomp (char *str)
{
    int len;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';
    return (str);
}
