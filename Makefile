# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikus <mikus@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 12:10:47 by fcasaubo          #+#    #+#              #
#    Updated: 2024/04/13 14:31:46 by mikus            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo
SRC_DIR		:=	src
BONUS_DIR	:=	bonus
SRC			:=	main.c			\
				execution.c		\
				free_things.c	\
				philo_list.c	\
				utils.c			\
				print_event.c	\
				routine.c		\
				one_case.c

BSRC		:=	main_bonus.c		\
				execution_bonus.c	\
				free_things_bonus.c	\
				philo_list_bonus.c	\
				utils_bonus.c		\
				print_event_bonus.c	\
				routine_bonus.c		\
				one_case_bonus.c

OBJ_DIR	:=	obj
OBJ		:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
BOBJ	:=	$(BSRC:%.c=$(OBJ_DIR)/%.o)

CC		:=	gcc
CCFLAGS	:=	-Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@clear
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

bonus: $(BOBJ)
	@clear
	@$(CC) $(CCFLAGS) $(BOBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $(CCFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $(CCFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean:
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re