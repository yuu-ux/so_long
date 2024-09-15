/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:38:18 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 21:52:02 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&(s[len]));
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *str = "hello";
// 	int c = 'z';

// 	printf("%s\n", strrchr(str, c));
// 	printf("%s\n", ft_strrchr(str, c));
// 	return (0);
// }