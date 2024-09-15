/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:00:24 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 16:51:28 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
//     t_list *lst;
//     t_list *new_node;

//     lst = ft_lstnew("world");
//     new_node = ft_lstnew("hello");
//     printf("Before: lst = %p new-node->next：%p\n", lst, new_node->next);
//     ft_lstadd_front(&lst, new_node);
// 	printf("After: lst = %p, new->next = %p\n", lst, new_node->next);
// 	return (0);
// }