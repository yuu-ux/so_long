/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:41:49 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 16:51:43 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main(void)
// {
//     t_list *lst;
//     t_list *node;
//     t_list *last_node;

//     lst = ft_lstnew("Hanako");
//     node = ft_lstnew("Tarou");

//     ft_lstadd_front(&lst, node);
// 	last_node = ft_lstlast(lst);
//     printf("%s\n", last_node->content);
//     return (0);
// }