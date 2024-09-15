/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:58 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 20:39:46 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int main(void)
// {
//     int a;
//     int b;

//     a = 128;
//     b = 3;
//     printf("%d\n", ft_isascii(a));
//     printf("%d\n", isascii(a));
//     printf("%d\n", ft_isascii(b));
//     printf("%d\n", isascii(b));
// }