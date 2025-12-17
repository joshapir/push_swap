# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joshapir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 22:40:02 by joshapir          #+#    #+#              #
#    Updated: 2025/02/11 21:17:05 by joshapir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program names
NAME = push_swap
NAME_BONUS = checker

# Compiler and flags
CC = cc
CFLAGS =

# Directories
SRC_DIR = src
BONUS_DIR = bonus
INC_DIR = includes
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

# Source files
SRC_FILES = main.c \
			algorithm.c \
			errors.c \
			movements.c \
			movements_utils.c \
			cost_utils.c \
			index_utils.c \
			free_stack.c \
			target_utils.c \
			sort_three.c \
			utils.c

BONUS_FILES = main_bonus.c \
			  checker_utils_bonus.c \
			  errors_bonus.c \
			  movements_bonus.c \
			  movements_utils_bonus.c \
			  cost_utils_bonus.c \
			  index_utils_bonus.c \
			  free_stack_bonus.c \
			  target_utils_bonus.c \
			  sort_three_bonus.c \
			  utils_bonus.c \
			  get_next_line_bonus.c \
			  get_next_line_utils_bonus.c

# Headers
INCLUDE = $(INC_DIR)/push_swap.h
INCLUDE_BONUS = $(INC_DIR)/push_swap_bonus.h $(INC_DIR)/get_next_line_bonus.h

# Full paths
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

# Object files
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(BONUS_FILES:.c=.o))

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✓ push_swap compiled successfully$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(INCLUDE_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ checker compiled successfully$(RESET)"

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(INCLUDE_BONUS)
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)✗ Executables removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
