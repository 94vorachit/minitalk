/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:58:05 by vorhansa          #+#    #+#             */
/*   Updated: 2026/04/17 23:27:18 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h> //INT_MIN
# include <stdarg.h> // va_list, va_start, va_end, va_arg
# include <unistd.h>
# include <stddef.h> //size_t

int	ft_printf(const char *format, ...);
int	print_str(char const *str);
int	print_int(int n);
int	print_unsigned(unsigned int nbr);
int	print_hex(unsigned int nbr, int upper_case);
int	print_ptr(void *adr);

int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif