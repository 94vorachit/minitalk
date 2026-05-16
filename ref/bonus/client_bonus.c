/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:11:11 by naratass          #+#    #+#             */
/*   Updated: 2026/04/29 17:16:15 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_status = 0;

static void	ack(int signal)
{
	(void)signal;
	ft_fputstr("SEND SUCCESS\n", 1);
	g_status = 1;
}

void	send_signal(pid_t server_pid, const unsigned char character)
{
	unsigned char	buf;
	int				mask;
	int				i;

	buf = character;
	mask = 0b10000000;
	i = 0;
	while (i++ < 8)
	{
		g_status = 0;
		if (buf & mask)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_exit(SENDING_ERROR);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_exit(SENDING_ERROR);
		}
		mask >>= 1;
		while (g_status != 1)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		ft_fputstr("format error!\nformat: ./client <server_pid> <text>", 2);
		exit(1);
	}
	i = 0;
	server_pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, ack) == SIG_ERR)
		error_exit(SENDING_ERROR);
	while (argv[2][i])
		send_signal(server_pid, argv[2][i++]);
	send_signal(server_pid, '\0');
	return (0);
}
