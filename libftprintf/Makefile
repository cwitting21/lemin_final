# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 20:16:44 by cwitting           #+#    #+#              #
#    Updated: 2019/11/10 17:03:16 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
SRC_DIR = ./srcs
INC = ./includes/
OBJ_DIR = ./obj

SRC := $(shell ls $(SRC_DIR))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m
CYAN = \033[0;36m

all:$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(SRCS) -I $(INC) -I $(LIB_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean
