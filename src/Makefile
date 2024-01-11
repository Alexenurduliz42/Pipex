# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:20:43 by ahiguera          #+#    #+#              #
#    Updated: 2024/01/11 15:32:42 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = 
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clear:
	@make -C libft fclean
	@rm -rf $(OBJ)

fclean: clear
	@rm -rf $(NAME)

re: fclean all

.phony: all clear fclean re