/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:07:16 by yehara            #+#    #+#             */
/*   Updated: 2024/05/04 00:05:50 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new_node;
//     t_list *lst_next;

// 	lst = ft_lstnew("Hanako");
// 	new_node = ft_lstnew("Nanako");
// 	printf("%s\n", lst->content);
// 	ft_lstadd_back(&lst, new_node);
// 	lst_next = lst->next;
// 	printf("%s\n", lst_next->content);
// }
