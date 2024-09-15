/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:23:57 by yehara            #+#    #+#             */
/*   Updated: 2024/05/03 16:17:05 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		str = n % 10 + '0';
		write(fd, &str, 1);
	}
	else
	{
		str = n + '0';
		write(fd, &str, 1);
	}
}

// int	main(void)
// {
// 	int	fd;
// 	int n;

//     n = INT_MIN + 1;
// 	fd = open("file.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// }
