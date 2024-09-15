/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:58:06 by yehara            #+#    #+#             */
/*   Updated: 2024/04/27 17:44:58 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	int	len = 30;
// 	char *str = calloc(30, sizeof(char));
// 	char *cmp = calloc(30, sizeof(char));

// 	for (int i = 0; i <= len; i++)
// 		{
// 			cmp = strndup(str, i);
// 			printf("%d回目：%c\n",i, cmp[i]);
// 			printf("%d %d\n",ft_memcmp(str, cmp, i), memcmp(str, cmp, i));
// 			// printf("%d %d\n",ft_memcmp(str, cmp, len), memcmp(str, cmp, len));
// 			free(cmp);
// 		}
//     return (0);
// }

// 8回目のループの挙動がおかしい
// 0を返したいが、-32が帰ってきている
// callocで30個の0を入れている
// cmpに関してはstrndupで30個の０を保持しているstrをi文字メモリを新しく割り当てる

//(str1[i] != '\0' && str2[i] != '\0') ||