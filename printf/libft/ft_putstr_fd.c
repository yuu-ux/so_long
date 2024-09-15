/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:52:52 by yehara            #+#    #+#             */
/*   Updated: 2024/05/01 22:03:20 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
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