# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 13:41:24 by vorhansa          #+#    #+#              #
#    Updated: 2026/04/17 23:27:37 by vorhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
HEADERS	= libft.h

#SRCS = ft_printf.c print_hex.c print_int.c print_ptr.c print_str.c print_unsigned.c ft_atoi.c
#OBJS = $(SRCS:.c=.o)
OBJ = ft_printf.o print_hex.o print_int.o print_ptr.o print_str.o print_unsigned.o ft_isdigit.o ft_atoi.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
# ar - create, modify, and extract from archives
# r   Insert the files member
# s   Write an object-file index into the archive
# c   Create the archive

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
