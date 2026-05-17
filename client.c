/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:11:30 by vorhansa          #+#    #+#             */
/*   Updated: 2026/05/17 20:55:05 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

static volatile sig_atomic_t	g_status = 0;

static void	ack(int signal)
{
	(void)signal;
	g_status = 1;
}

static int	parse_pid(char *str, pid_t *pid)
{
	long	value;

	if (!str || !str[0])
		return (0);
	value = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = (value * 10) + (*str - '0');
		if (value > INT_MAX)
			return (0);
		str++;
	}
	if (value <= 0)
		return (0);
	*pid = (pid_t)value;
	return (1);
}

int	send_signal(pid_t pid, unsigned char character)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		g_status = 0;
		if (((character >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		while (g_status != 1)
			pause();
	}
	return (1);
}

static int	send_message(pid_t server_pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		if (!send_signal(server_pid, message[i++]))
			return (0);
	}
	return (send_signal(server_pid, '\0'));
}

int	main(int ac, char **av)
{
	pid_t		server_pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", av[0]);
		exit (1);
	}
	if (!parse_pid(av[1], &server_pid) || kill(server_pid, 0) == -1)
	{
		ft_printf("PID ERROR\n");
		exit (1);
	}
	if (signal(SIGUSR1, ack) == SIG_ERR)
	{
		ft_printf("SIGNAL ERROR\n");
		exit (1);
	}
	if (!send_message(server_pid, av[2]))
	{
		ft_printf("SEND MESSAGE ERROR\n");
		exit (1);
	}
	return (0);
}
