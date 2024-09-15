/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:47:28 by yehara            #+#    #+#             */
/*   Updated: 2024/05/12 15:56:08 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 && haystack == NULL)
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((needle[j] != '\0') && (haystack[i + j] == needle[j])
				&& (i + j < len))
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//    char *str = "libft-test-tokyo"; //16文字
//    int len = strlen(str); //len = 16
//    for (int i = 0; i < len; i++)
//    {
//        printf("%s %s\n", ft_strnstr(str, "libft", i),
// strnstr(str, "libft", i));
//        printf("%s %s\n", ft_strnstr(str, "test", i),
// strnstr(str, "test", i));
//        printf("%s %s\n", ft_strnstr(str, "tokyo", i),
// strnstr(str, "tokyo", i));
//        printf("%s %s\n", ft_strnstr(str, "z", i), strnstr(str, "z", i));
//    }
//    return (0);
// }