/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:28:13 by yehara            #+#    #+#             */
/*   Updated: 2024/05/03 21:08:59 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int main(void)
// {
//     char *content = "Hello, world!";
//     t_list *node = ft_lstnew(content);

//     if (node == NULL)
//     {
//         printf("Error: Failed to create a new node.\n");
//         return (1);
//     }

//     printf("Content: %s\n", node->content);
//     printf("Next: %p\n", node->next);

//     // nodeを解放する
//     free(node);

//     return (0);
// }