/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:31:38 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 16:31:10 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	p_dgts(unsigned long n)
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

static void	put_ptr(unsigned long adr)
{
	static char	dgts[] = "0123456789abcdef";

	if (adr >= 16)
		put_ptr(adr / 16);
	write(1, &dgts[adr % 16], 1);
}

int	print_ptr(void *adr)
{
	if (adr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_ptr((unsigned long)adr);
	return (p_dgts((unsigned long)adr) + 2);
}
