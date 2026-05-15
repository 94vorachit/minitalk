/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:04:57 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 16:30:03 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	h_dgts(unsigned int n)
{
	size_t	dgt;

	dgt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		dgt += 1;
		n /= 16;
	}
	return (dgt);
}

static void	put_hex(unsigned int nbr, int upper_case)
{
	static char	upper_dgts[] = "0123456789ABCDEF";
	static char	lower_dgts[] = "0123456789abcdef";

	if (nbr >= 16)
		put_hex(nbr / 16, upper_case);
	if (upper_case)
		write(1, &upper_dgts[nbr % 16], 1);
	else
		write(1, &lower_dgts[nbr % 16], 1);
}

int	print_hex(unsigned int nbr, int upper_case)
{
	put_hex(nbr, upper_case);
	return (h_dgts(nbr));
}
