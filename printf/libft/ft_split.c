/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:56:49 by yehara            #+#    #+#             */
/*   Updated: 2024/05/05 20:13:21 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*allocate_buf(char **buf, int len, int i)
{
	buf[i] = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
	{
		i--;
		while (0 <= i)
			free(buf[i--]);
		return (NULL);
	}
	return (buf[i]);
}

static char	**split_string(char **buf, char const *s, char c)
{
	int	word_length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*(s) == '\0')
			break ;
		word_length = word_len(s, c);
		if (allocate_buf(buf, word_length, i) == NULL)
			return (NULL);
		while (j < word_length)
		{
			buf[i][j++] = *s++;
		}
		buf[i][j] = '\0';
		j = 0;
		i++;
	}
	buf[i] = NULL;
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**buf;

	words = 0;
	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	buf = (char **)malloc((words + 1) * sizeof(char *));
	if (buf == NULL)
		return (NULL);
	buf = split_string(buf, s, c);
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
// int	main(void)
// {
// char *str;
// char delimiter;
// char **result;
// int i;

// i = 0;
// str = "a,b,c";
// delimiter = ',';

// result = ft_split(str, delimiter);
// while (result[i] != NULL)
// {
// 	printf("%s", result[i]);
// 	i++;
// }
// printf("%s\n", ft_split(str, delimiter));
// char *expected[] = {"hello","world","42","tokyo", NULL};
// /* 1 ~ 5 */ printf("%s\n", ft_split("hello,world,42,tokyo", ','));
// /* 6 ~ 10 */ printf(ft_split("hello world 42 tokyo", ' '));
// /* 11 ~ 15 */ printf(ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ','));

// char *expected2[] = {"hello,world,42,tokyo", NULL};
// /* 16 ~ 17 */ printf(ft_split("hello,world,42,tokyo", ' '));
// /* 18 ~ 19 */ printf(ft_split("hello,world,42,tokyo", '{'));

// char *expected3[] = {NULL};
// /* 20 */ printf(ft_split("", ','));
// }