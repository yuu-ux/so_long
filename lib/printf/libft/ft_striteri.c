/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:28:22 by yehara            #+#    #+#             */
/*   Updated: 2024/05/01 20:24:29 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	t_tolower(unsigned int i, char *str)
// {
// 	if (str[i] >= 'A' && str[i] <= 'Z')
// 	{
// 		str[i] += 32;
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int main(void)
// {
// 	char *str;
//     str = ft_strdup("Hello");
//     printf("%s\n", str);
//     printf("%p\n", str);
//     ft_striteri(str, t_tolower);
//     printf("%s\n", str);
//     printf("%p\n", str);
//     free(str);
// }