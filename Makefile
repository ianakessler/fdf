# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:23:19 by iaratang          #+#    #+#              #
#    Updated: 2025/11/13 15:57:49 by iaratang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =	srcs/main.c\
		srcs/get_next_line_utils.c\
		srcs/get_next_line.c\

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./lib
LIBFT_A = $(LIBFT_PATH)/libft.a

INCLUDES_PATH = ./includes

INCLUDE = -I$(INCLUDES_PATH)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "FDF Compilado com sucesso"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
