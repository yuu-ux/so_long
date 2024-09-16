/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:43:15 by yehara            #+#    #+#             */
/*   Updated: 2024/05/04 21:29:21 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *str_to_bigstr(void *content)
// {
//     char *str = (char *)content;
//     while (*str)
//     {
//         if (*str >= 'a' && *str <= 'z')
//             *str -= 32;
//         str++;
//     }
//     return (str);
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int	main(void)
// {
// 	t_list *lst;
// 	t_list *lst2;
//     lst = ft_lstnew("hello");
//     lst2 = ft_lstnew("world");
//     ft_lstadd_back(&lst, lst2);
// 	ft_lstiter(lst, str_to_bigstr);
// }