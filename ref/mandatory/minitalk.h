/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:06:57 by naratass          #+#    #+#             */
/*   Updated: 2026/04/29 17:18:22 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define SENDING_ERROR "signal error!\n" 

int		ft_atoi(const char *nptr);
int		ft_fputchar(char c, int fd);
void	ft_fputnbr_deci(long n);
void	ft_fputstr(char *str, int fd);
void	error_exit(char *s);

#endif
