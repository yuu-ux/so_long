/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:23:47 by yehara            #+#    #+#             */
/*   Updated: 2024/05/03 22:05:54 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	t_list *lst;
//     t_list *new_node;
//     lst = ft_lstnew("World");
//     new_node = ft_lstnew("Hello");
//     printf("%d\n", ft_lstsize(lst));
// 	ft_lstadd_front(&lst, new_node);
//     printf("%d\n", ft_lstsize(lst));
//     return (0);
// }