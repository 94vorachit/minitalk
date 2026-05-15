/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:53:20 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 16:31:06 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	i_dgts(int n)
{
	size_t	dgt;

	dgt = 0;
	if (n <= 0)
		dgt += 1;
	while (n != 0)
	{
		n /= 10;
		dgt += 1;
	}
	return (dgt);
}

static void	put_int(int n)
{
	static char	dgts[] = "0123456789";

	if (n > 9)
		put_int(n / 10);
	write(1, &dgts[n % 10], 1);
}

int	print_int(int n)
{
	int	len;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	len = i_dgts(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	put_int(n);
	return (len);
}
