/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:18:23 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 16:30:58 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	ltr_case(char ltr, va_list args)
{
	if (ltr == '%')
		return (write(1, "%", 1));
	if (ltr == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (ltr == 's')
		return (print_str(va_arg(args, char *)));
	if (ltr == 'd' || ltr == 'i')
		return (print_int(va_arg(args, int)));
	if (ltr == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (ltr == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	if (ltr == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	if (ltr == 'p')
		return (print_ptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		cnt;

	if (!format)
		return (-1);
	i = 0;
	cnt = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			cnt += ltr_case(format[i], args);
		}
		else
			cnt += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (cnt);
}

// int	main()
// {
// 	int	a = 42;
// 	unsigned int a2 = 123456789;
// 	char	b[] = "asdfghjkl";
// 	char	c = 'C';
// 	ft_printf("%%The number is %i,%d,%u,%x,%X\n"
// 	"The string is %s,%c,%p\n", a, a, a2, a, a, b, c, b);
// }

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		ft_printf("Usage: %s <pid> <message>\n", av[0]);
// 	else
// 		ft_printf("OK : %s", av[1]);
// 	return (0);
// }