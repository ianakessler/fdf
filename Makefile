# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:23:19 by iaratang          #+#    #+#              #
#    Updated: 2025/12/03 18:35:40 by iaratang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =	srcs/main.c\
		srcs/mapping.c\
		srcs/file_validator.c\
		srcs/free_allocs.c\
		srcs/utils.c\
		srcs/fill_map.c\
		srcs/isometric_projection.c\
		srcs/DDA.c\


OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./lib
LIBFT_A = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = ./minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

INCLUDES_PATH = ./includes

INCLUDE = -I$(INCLUDES_PATH)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MINILIBX) -lm -lX11 -lXext -o $@
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
