/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:50:26 by naratass          #+#    #+#             */
/*   Updated: 2026/04/29 17:19:05 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		sum = (sum * 10) + (*nptr - '0');
		nptr++;
	}
	return (sign * sum);
}

int	ft_fputchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_fputnbr_deci(long n)
{
	if (n == 0)
	{
		ft_fputchar('0', 1);
		return ;
	}
	if (n < 0)
	{
		ft_fputchar('-', 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_fputnbr_deci(n / 10);
		ft_fputnbr_deci(n % 10);
	}
	else
		ft_fputchar(n + '0', 1);
}

void	ft_fputstr(char *str, int fd)
{
	int	cnt;

	if (!str)
		return ;
	cnt = 0;
	while (str[cnt])
		ft_fputchar(str[cnt++], fd);
}

void	error_exit(char *s)
{
	if (!s)
		return ;
	ft_fputstr(s, 2);
	exit(1);
}
