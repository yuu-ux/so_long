/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:46 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 20:28:28 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

// int	main(void)
// {
// 	int ft_a = '1';
// 	int a = '1';
// 	int ft_b = 0;
// 	int b = 0;

// 	printf("%d\n", ft_isdigit(ft_a));
// 	printf("%d\n", isdigit(a));
// 	printf("%d\n", ft_isdigit(ft_b));
// 	printf("%d\n", isdigit(b));

// 	return (0);
// }