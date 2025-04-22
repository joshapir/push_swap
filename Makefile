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

NAME = push_swap
NAME_BONUS = checker

SRC = errors.c movements.c main.c target_utils.c cost_utils.c\
	free_stack.c index_utils.c sort_three.c utils.c algorithm.c movements_utils.c

SRC_BONUS = errors_bonus.c  movements_bonus.c main_bonus.c target_utils_bonus.c \
    cost_utils_bonus.c free_stack_bonus.c index_utils_bonus.c sort_three_bonus.c utils_bonus.c movements_utils_bonus.c checker_utils_bonus.c \
    get_next_line_bonus.c get_next_line_utils_bonus.c

INCLUDE = push_swap.h
INCLUDE_BONUS = push_swap_bonus.h get_next_line_bonus.h

CFLAGS = -Wall -Werror -Wextra
CC  = cc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

$(NAME_BONUS): $(OBJ_BONUS) $(INCLUDE_BONUS)
		$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c  push_swap.h push_swap_bonus.h get_next_line_bonus.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all		

.PHONY: all clean fclean re bonus

