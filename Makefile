# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 12:10:47 by fcasaubo          #+#    #+#              #
#    Updated: 2024/04/02 13:33:25 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo
SRC_DIR	:=	src
SRC		:=	main.c			\
			execution.c		\
			free_things.c	\
			philo_list.c	\
			utils.c			\
			print_event.c	\
			routine.c		\
			one_case.c

OBJ_DIR	:=	obj
OBJ		:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC		:=	gcc
CCFLAGS	:=	-Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@clear
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $(CCFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean:
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re