/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:39:23 by yehara            #+#    #+#             */
/*   Updated: 2024/05/08 21:14:12 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
// int	main(void)
// {
// 	int c;
// 	int d;
// 	c = tolower('a');
// 	d = ft_tolower('a');
// 	printf("%c\n", c);
// 	printf("%c\n", d);
// }