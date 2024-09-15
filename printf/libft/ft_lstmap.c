/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:14:29 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 21:17:09 by yehara           ###   ########.fr       */
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

// void	del_content(void *content)
// {
// 	free(content);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
// int	main(void)
// {
//     t_list *lst;

//     lst = ft_lstnew("TAROU");
//     printf("%s\n", lst->content);
//     ft_lstmap(lst, str_to_bigstr, del_content);
//     printf("%s\n", lst->content);
// 	return (0);
// }