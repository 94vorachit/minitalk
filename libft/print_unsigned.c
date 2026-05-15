/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:44:56 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 16:31:22 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	u_dgts(unsigned int n)
{
	size_t	dgt;

	dgt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		dgt += 1;
	}
	return (dgt);
}

static void	put_unsigned(unsigned int nbr)
{
	static char	dgts[] = "0123456789";

	if (nbr > 9)
		put_unsigned(nbr / 10);
	write(1, &dgts[nbr % 10], 1);
}

int	print_unsigned(unsigned int nbr)
{
	put_unsigned(nbr);
	return (u_dgts(nbr));
}
