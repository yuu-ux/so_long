/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:49:39 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 00:40:31 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	to_upper(unsigned int index, char c)
// {
// 	(void)index;
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		return (c - 32);
// 	}
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buf;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

// int main(void)
// {
// 	char *s;
//     s = "abcde";
//     // char (*f)(unsigned int, char);
//     // f = increment_char;
//     printf("%s\n", s);
//     printf("%p\n", s);
// 	s = ft_strmapi(s, to_upper);
//     printf("%s\n", s);
//     printf("%p\n", s);
// }