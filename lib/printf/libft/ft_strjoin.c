/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:28:58 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 01:07:00 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	total_len;
	char	*buf;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	total_len = lens1 + lens2;
	buf = (char *)malloc((total_len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, s1, lens1 + 1);
	ft_strlcat(buf, (char *)s2, total_len + 1);
	return (buf);
}

// int main(void)
// {
// 	/* 1 */ printf("1：%s\n", ft_strjoin("hello", "world")); // "helloworld"
// 	/* 2 */ printf("2：%s\n", ft_strjoin("", "world")); // "world"
// 	/* 3 */ printf("3：%s\n", ft_strjoin("hello", "")); // "hello"
// 	/* 4 */ printf("4：%s\n", ft_strjoin("", "")); // ""
// 	return 0;
// }