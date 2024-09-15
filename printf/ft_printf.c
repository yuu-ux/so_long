/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:24:10 by yehara            #+#    #+#             */
/*   Updated: 2024/05/16 20:45:07 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_formatted(const char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printf_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_printf_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_printf_ptr(va_arg(ap, void *));
	else if (specifier == 'd')
		count += ft_printf_dec(va_arg(ap, int));
	else if (specifier == 'i')
		count += ft_printf_dec(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_printf_unsigned_dec(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_printf_hex(va_arg(ap, unsigned int), ft_tolower);
	else if (specifier == 'X')
		count += ft_printf_hex(va_arg(ap, unsigned int), ft_toupper);
	else
		count += ft_printf_char(specifier);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			count += print_formatted(*(str + 1), ap);
			str++;
		}
		else
			count += ft_printf_char(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	char			c;
// 	char			*s;
// 	char			*p;
// 	int				d;
// 	int				i;
// 	unsigned int	u;
// 	int				x;
// 	int				X;

// 	c = '\0';
// 	s = NULL;
// 	p = NULL;
// 	d = -2147483648;
// 	i = -2147483648;
// 	u = -2147483645;
// 	x = 10;
// 	X = 10;
// 	printf("%d\n", ft_printf("1文字表示する：%c\n", c));
// 	printf("%d\n", printf("1文字表示する：%c\n", c));
// 	printf("%d\n", ft_printf("文字列を表示する：%s\n", s));
// 	printf("%d\n", printf("文字列を表示する：%s\n", s));
// 	printf("%d\n", ft_printf("アドレスを表示する：%p\n", p));
// 	printf("%d\n", printf("アドレスを表示する：%p\n", p));
// 	printf("%d\n", ft_printf("10進数を表示する：%d\n", d));
// 	printf("%d\n", printf("10進数を表示する：%d\n", d));
// 	printf("%d\n", ft_printf("10進数を表示する：%i\n", i));
// 	printf("%d\n", printf("10進数を表示する：%i\n", i));
// 	printf("%d\n", ft_printf("整数の10進数を表示する：%u\n", u));
// 	printf("%d\n", printf("整数の10進数を表示する：%u\n", u));
// 	printf("%d\n", ft_printf("16進数を小文字で表示する：%x\n", x));
// 	printf("%d\n", printf("16進数を小文字で表示する：%x\n", x));
// 	printf("%d\n", ft_printf("16進数を大文字で表示する：%X\n", X));
// 	printf("%d\n", printf("16進数を大文字で表示する：%X\n", X));
// 	printf("%d\n", ft_printf("％を表示する：%%%%%%\n"));
// 	printf("%d\n", printf("％を表示する：%%%%%%\n"));
// 	return (0);
// }