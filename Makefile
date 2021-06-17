# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obounri <obounri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 16:20:43 by obounri           #+#    #+#              #
#    Updated: 2021/06/17 15:33:23 by obounri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes/minitalk.h

PROG1 = client
PROG2 = server

SRCS = 

LIBFT_MAKEFILE_PATH = srcs/libft/ 
LIBFT = srcs/libft/libft.a

all: $(PROG1) $(PROG2)

$(PROG1): $(SRCS) $(LIBFT) $(HEADER) client.c
	$(CC) $(CFLAGS) client.c $(SRCS) $(LIBFT) -o $(PROG1)

$(PROG2): $(SRCS) $(LIBFT) $(HEADER) server.c
	$(CC) $(CFLAGS) server.c $(SRCS) $(LIBFT) -o $(PROG2)
	
$(LIBFT): $(LIBFT_SRCS)
	make -C $(LIBFT_MAKEFILE_PATH)

clean:
	make -C $(LIBFT_MAKEFILE_PATH) clean

fclean: clean
	rm -f $(PROG1) $(PROG2) $(LIBFT)

re: fclean all
