/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:06:51 by naratass          #+#    #+#             */
/*   Updated: 2026/04/29 17:10:52 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	const unsigned char	chr = c;
	unsigned char		*p;

	p = s;
	while (n-- > 0)
		*p++ = chr;
	return (s);
}

void	handler_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				bit = 0;

	(void)context;
	bit++;
	character |= (signal == SIGUSR1);
	if (bit == 8)
	{
		if (character == '\0')
			ft_fputchar('\n', 1);
		else
			ft_fputchar(character, 1);
		bit = 0;
		character = 0;
	}
	else
		character <<= 1;
	if (kill(info->si_pid, SIGUSR1) == -1)
		error_exit(SENDING_ERROR);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_fputstr("PID: ", 1);
	ft_fputnbr_deci(getpid());
	ft_fputchar('\n', 1);
	if (sigaction(SIGUSR1, &sa, NULL))
		error_exit(SENDING_ERROR);
	if (sigaction(SIGUSR2, &sa, NULL))
		error_exit(SENDING_ERROR);
	while (1)
		pause();
	return (0);
}
