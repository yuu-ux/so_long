/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:42:03 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 20:01:14 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int	main(void)
// {
//     int a;
//     int b;
// 	int ft_a = ft_isalpha('a');
// 	a = isalpha('a');
// 	int ft_b = ft_isalpha('1');
// 	b = isalpha('1');

//     printf("%d\n", ft_a);
//     printf("%d\n", a);
//     printf("%d\n", ft_b);
//     printf("%d\n", b);

//     return (0);
// }