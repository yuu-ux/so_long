/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:52:59 by yehara            #+#    #+#             */
/*   Updated: 2024/05/04 23:49:36 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char str[] = "libft-test-tokyo";
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	cmp2[5] = CHAR_MIN;
// 	int len = 16;
// 	printf("%s\n", cmp2);
//     printf("ABC: ABD   = %d\n", strncmp(str, cmp2, len));
//     printf("ABC: ABC   = %d\n", strncmp(str, cmp2, len));
//     // printf("ABC: AAA   = %d\n", strncmp(str, "AAA", 2));
//     // printf("ABC: ABCD  = %d\n", strncmp(str, "ABCD", 2));
//     // printf("ABC: AB    = %d\n", strncmp(str, "AB", 2));
//     // printf("ABC: B     = %d\n", strncmp(str, "B", 2));
//     // printf("ABC: A     = %d\n", strncmp(str, "A", 2));

//     for (int i = 0; i < 50; i++)
//     	printf("-");
//     printf("\n");

//     printf("ABC: ABD   = %d\n", ft_strncmp(str, cmp2, len));
//     printf("ABC: ABC   = %d\n", ft_strncmp(str, cmp2, len));
//     // printf("ABC: AAA   = %d\n", ft_strncmp(str, "AAA", 2));
//     // printf("ABC: ABCD  = %d\n", ft_strncmp(str, "ABCD", 2));
//     // printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
//     // printf("ABC: B     = %d\n", ft_strncmp(str, "B", 2));
//     // printf("ABC: A     = %d\n", ft_strncmp(str, "A", 2));

//     return (0);
// }
