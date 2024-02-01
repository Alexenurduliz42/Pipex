# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:20:43 by ahiguera          #+#    #+#              #
#    Updated: 2024/01/23 19:29:08 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CFLAGS 	= -Wall -Wextra -Werror
SILENCE = -s

SRCS 	= src/pipex.c src/utils.c
OBJS 	= ${SRCS:.c=.o}

LIBFT_DIR = ./Libft_2.0/

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "\033[32m *** Compiling dependencies... ***"
					@make re -C $(LIBFT_DIR) ${SILENCE}
					@make clean -C $(LIBFT_DIR) ${SILENCE}
					@gcc ${OBJS} -L Libft_2.0 -lft -o ${NAME}
					@echo "\033[36m Pipex Compiled! o.o\n"

clean:
					@make clean -C $(LIBFT_DIR)
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C $(LIBFT_DIR) ${SILENCE}
					@rm -f $(NAME)
					@rm -fr infile outfile
					@echo "\n\033[35m Deleting EVERYTHING! (-_-)\n"
					@echo "$$ART"

re:			fclean all

.PHONY: all clean fclean re

#------------------------------------------------#
#   ASCII ART                                    #
#------------------------------------------------#

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

define	ART
$(YELLOW)
(alex) /^-^\         /^-----^\\
      / o o \        V  o o  V
     /   ▼   \        |  ▽  |  
     V \ ∧ / V         \ Q / 
       / - \\ ========= / - \\
      /    |   Pipex   |    \\
("   /     |           |     \\     )"
 ===/___) || ========= || (___\\====$(CLR_RMV)
endef
export	ART