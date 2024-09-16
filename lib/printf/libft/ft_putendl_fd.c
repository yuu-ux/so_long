/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:14:25 by yehara            #+#    #+#             */
/*   Updated: 2024/05/01 22:04:07 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int	fd;
// 	char *str;

//     str = "abcde";
// 	fd = open("file.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	ft_putstr_fd(str, fd);
// 	close(fd);
// }
