/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:31 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 22:00:09 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #define BUF_SIZE 16

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	*str;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	buf = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
	return (buf);
}

// int main(void)
// {
//     size_t num = 6;
//     char *src = "hello";
//     char *ft_src = "hello";
//     char dst[BUF_SIZE];
//     char ft_dst[BUF_SIZE];

//     printf("コピー前: %s\n", dst);
//     printf("コピー前: %s\n", ft_dst);
//     memcpy(dst, src, num);
//     ft_memcpy(ft_dst, ft_src, num);
//     printf("コピー後: %s\n", dst);
//     printf("コピー後: %s\n", ft_dst);
//     return (0);
// }