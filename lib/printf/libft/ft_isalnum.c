/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:42:08 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 20:28:41 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
// int main(void)
// {
//     int a;
//     int b;

//     a = 0;
//     b = '0';

//     printf("%d\n", ft_isalnum(a));
//     printf("%d\n", isalnum(a));
//     printf("%d\n", ft_isalnum(b));
//     printf("%d\n", isalnum(b));

//     return (0);
// }
