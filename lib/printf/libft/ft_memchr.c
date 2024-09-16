/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:20 by yehara            #+#    #+#             */
/*   Updated: 2024/05/04 21:50:19 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     long long num = INT_MAX;
//     int ch = 8;
//     size_t n = 30;
// 	printf("%s\n", memchr(&num, ch, n));
// 	printf("%s\n", ft_memchr(&num, ch, n));
//     return (0);
// }

// /* 17 */ (ft_memchr(s, '\0', 30), memchr(s, '\0', 30));
// /* 24 */ (ft_memchr(s, 'a', 30), memchr(s, 'a', 30));
// /* 25 */ (ft_memchr(s, 'c', 30), memchr(s, 'c', 30));
// /* 26 */ (ft_memchr(s, 'd', 30), memchr(s, 'd', 30));
// /* 28 */ (ft_memchr(s, 'g', 30), memchr(s, 'g', 30));