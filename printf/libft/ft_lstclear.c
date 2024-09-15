/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:48:11 by yehara            #+#    #+#             */
/*   Updated: 2024/05/04 04:09:55 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	deleate_content(void *content)
// {
// 	free(content);
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = temp;
	}
	lst = NULL;
}

// int	main(void)
// {
// 	t_list *lst;
// 	lst = ft_lstnew("content");
// 	printf("%p\n", lst);
// 	ft_lstclear(&lst, del_content);
//     printf("%p\n", lst);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }