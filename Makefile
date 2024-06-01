# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:42:24 by jhouyet           #+#    #+#              #
#    Updated: 2024/06/01 12:51:35 by jhouyet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME		= philo

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/

SRC 		= 	$(SRC_DIR)main.c \
				$(SRC_DIR)args.c \
				$(SRC_DIR)philosophers.c \
				$(SRC_DIR)monitoring.c \
				$(SRC_DIR)utils.c \
				$(SRC_DIR)time.c \
				$(SRC_DIR)exit.c

OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -pthread
INCS 		= -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_philosophers
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling Philosophers... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/moves
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	$(call progress_bar_philosophers)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

clean:
	@echo "$(ORANGE)Cleaning objects for Philosophers...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@echo "$(GREEN)Cleaned Philosophers objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Philosophers...$(NC)"
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned Philosophers!$(NC)"

re: fclean all

.PHONY: all clean fclean re