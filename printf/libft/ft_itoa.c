/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:41 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 00:39:43 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*buf_secure(int digits, int flag)
{
	char	*buf;

	if (flag)
		buf = (char *)malloc((digits + 1) * sizeof(char));
	else
		buf = (char *)malloc((digits + 2) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	return (buf);
}

static char	*int_to_str(char *result, int digits, int flag, int n)
{
	long long	num;

	if (flag)
	{
		result[digits] = '\0';
		while (n != 0)
		{
			result[--digits] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		num = n;
		num *= -1;
		result[0] = '-';
		result[digits + 1] = '\0';
		while (num != 0)
		{
			result[digits--] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (result);
}

static char	*zero_processing(void)
{
	char	*result;

	result = (char *)malloc((1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = (char)(0 + '0');
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		digits_counts;
	char	*result;

	flag = 1;
	digits_counts = 0;
	if (n == 0 || n == +0 || n == -0)
	{
		result = zero_processing();
		if (result == NULL)
			return (NULL);
		return (result);
	}
	if (n < 0)
		flag = 0;
	digits_counts = digits_count(n);
	result = buf_secure(digits_counts, flag);
	if (result == NULL)
		return (NULL);
	result = int_to_str(result, digits_counts, flag, n);
	return (result);
}

// int main(void)
// {
// int n;
// n = -18729;
// printf("%s\n", ft_itoa(n));
// /* 1 */ printf("%s\n", ft_itoa(0)); // 0
// /* 2 */ printf("%s\n", ft_itoa(-0)); // 0
// /* 3 */ printf("%s\n", ft_itoa(+0)); // 0
// /* 14. INT_MIN */ printf("%s\n", ft_itoa(-2147483648)); //"-2147483648"
// /* 4 */ printf(ft_itoa(1),"1");
// /* 5 */ printf(ft_itoa(-1),"-1");
// /* 6 */ printf(ft_itoa(+1),"1");
// /* 7 */ printf(ft_itoa(7),"7");
// /* 8 */ printf(ft_itoa(-7),"-7");
// /* 9 */ printf(ft_itoa(+7),"7");
// /* 10 */ printf(ft_itoa(42), "42");
// /* 11 */ printf(ft_itoa(-42), "-42");
// /* 12 */ printf(ft_itoa(+42), "42");
// /* 13. INT_MAX */ printf(ft_itoa(2147483647),"2147483647");
// /* 15. INT_MAX - 1 */ printf(ft_itoa(2147483646), "2147483646");
// /* 16. INT_MIN + 1 */ printf(ft_itoa(-2147483647), "-2147483647");
//     return (0);
// }
