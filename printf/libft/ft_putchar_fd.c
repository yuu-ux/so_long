/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:23:57 by yehara            #+#    #+#             */
/*   Updated: 2024/05/01 22:07:19 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("file.txt", O_RDWR | O_APPEND, S_IREAD | S_IWRITE);
// 	ft_putchar_fd('a', fd);
// 	close(fd);
// }
