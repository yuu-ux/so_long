/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:06:05 by yehara            #+#    #+#             */
/*   Updated: 2024/04/28 19:47:17 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	is_in_set(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	re_len;
	char	*trim_front;
	char	*trim_end;
	char	*buf;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trim_front = (char *)s1;
	while (*trim_front && is_in_set(*trim_front, set))
			trim_front++;
	trim_end = (char *)s1 + ft_strlen(s1) - 1;
	while (trim_end > trim_front && is_in_set(*trim_end, set))
		trim_end--;
	re_len = trim_end - trim_front + 1;
	buf = malloc((re_len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, trim_front, re_len + 1);
	buf[re_len] = '\0';
	return (buf);
}

// int	main(void)
// {
	// printf("%zd\n", front_trim_count("abc  hello  abc", " abc")); //4を返したい
// 	/* 1 */ printf("1：%s\n", ft_strtrim("hello world", "world")); //"hello "
// 	/* 2 */ printf("2：%s\n", ft_strtrim("hello world", "hello"));//" world"
// 	/* 3 */ printf("3：%s\n", ft_strtrim("hello world", ""));//"hello world"
// 	/* 4 */ printf("4：%s\n", ft_strtrim("", ""));//""
// 	return (0);
// }
