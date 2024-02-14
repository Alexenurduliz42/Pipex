# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:20:43 by ahiguera          #+#    #+#              #
#    Updated: 2024/02/13 15:45:03 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CFLAGS 	= -Wall -Wextra -Werror
SILENCE = -s

SRCS 	= src/pipex.c src/utils.c
OBJS 	= ${SRCS:.c=.o}

LIBFT_DIR = ./Libft_2.0/

#------------------------------------------------#
#   ASCII COLORS                                 #
CLR_RMV		:= "\033[0m"
RED		    := "\033[1;31m"
GREEN		:= "\033[1;32m"
YELLOW		:= "\033[1;33m"
BLUE		:= "\033[1;34m"
CYAN 		:= "\033[1;36m"
#------------------------------------------------#

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo $(YELLOW) "Compiling dependencies....\n"
					@make re -C $(LIBFT_DIR) ${SILENCE}
					@make clean -C $(LIBFT_DIR) ${SILENCE}
					@gcc ${OBJS} -L Libft_2.0 -lft -o ${NAME}
					@echo $(GREEN) "Pipex Compiled!\n"

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

norm:
					@norminette src/*.c src/*.h

.PHONY: all clean fclean re norm

#------------------------------------------------#
#   ASCII ART                                    #

define	ART
$(CYAN)
(alex) /^-^\         /^-----^\\
      / o o \        V  o o  V
     /   ▼   \        |  ▽  |  
     V \ ∧ / V         \ Q / 
       / - \\ ========= / - \\
      /    |   Pipex   |    \\
("   /     |           |     \\     )"
 ===/___) || ========= || (___\\====$(CYAN)
endef
export	ART
#------------------------------------------------#