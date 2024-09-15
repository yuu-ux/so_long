/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:38:21 by yehara            #+#    #+#             */
/*   Updated: 2024/05/11 21:40:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ascii_to_int(const char *str, int flag)
{
	unsigned long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((result > LONG_MAX / 10)
			|| ((result == LONG_MAX / 10) && ((*str - '0') > 7)))
		{
			if (flag == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return ((int)(flag * result));
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	result;

	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	result = ascii_to_int(str, flag);
	return (result);
}

// int	main(void)
// {
// 	char *str = "-9223372036854775807";
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }
