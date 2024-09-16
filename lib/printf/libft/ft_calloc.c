/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:54:41 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 00:47:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (count && (size > SIZE_MAX / count))
		return (NULL);
	buffer = (void *)malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, count * size);
	return (buffer);
}

// #define ARRAY_SIZE 10

// int main() {
//     int *array = (int *)ft_calloc(ARRAY_SIZE, sizeof(int));
//     if (array == NULL) {
//         printf("メモリ割り当てに失敗しました。\n");
//         return (1);
//     }

//     // 配列の要素を初期化
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         array[i] = i + 1;
//     }

//     // 配列の要素の合計を計算
//     int sum = 0;
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         sum += array[i];
//     }

//     printf("配列の要素の合計: %d\n", sum);

//     // 割り当てられたメモリを解放
//     free(array);

//     return (0);
// }

// 好きな時に失敗する malloc()
// #if 1
// void    *malloc(size_t n)
// {
//     static int i = 0;

//     if (i++ < 42)
//         return (calloc(n, 1));
//     errno = ENOMEM;
//     return (NULL);
// }
// #endif