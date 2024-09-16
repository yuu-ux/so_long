/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:53 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 00:12:40 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
// int main(void)
// {
//     char *str = "abcde";

//     printf("original:%s\n", str);
//     printf("original:%s\n", strdup(str));
//     printf("original:%p\n", str);
//     printf("original:%p\n", strdup(str));
//     for (int i = 0; i < 100; i++)
//     {
//         printf("-");
//     }
//     printf("\n");

//     printf("ft:%p\n", str);
//     printf("ft:%s\n", ft_strdup(str));
//     printf("ft:%p\n", ft_strdup(str));
//     return (0);
// }
