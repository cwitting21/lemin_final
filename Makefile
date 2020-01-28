# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    d: 2020/01/11 17:05:08 by cwitting          #+#    #+#              #
#    Updated: 2020/01/20 03:11:48 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_FILES = lemin.c initialize_map.c \
			parse_map_to_struct.c ants.c connectivity_matrix.c functions.c \
			links.c rooms.c matrix_to_adj_list.c bfs_adj_list.c \
			reverse_edges.c ft_exit.c print_adj_list.c print_matrix.c \
			push_q.c pop_q.c add_to_way.c empty_q.c print_parents.c \
			print_shortest_path.c create_way.c print_way.c solve_map.c \
			print_name_index.c free_all.c print_map.c add_one_way.c \
			delete_intersections.c print_graph.c \
			distribute_ants.c del_q.c move_ants.c free_ready_ways.c del_sol.c \
			part_validation.c print_ready_ways.c print_solution.c del_way.c \
			solve_map_help1.c create_ready_way.c add_to_ready_way.c \
			create_best_sol.c set_ways.c copy_ways_to_sol.c

H_PATH = includes/

LIB_FT_PATH = libft/
LIB_PRINTF_PATH = libftprintf/

LIB_FT_A = $(LIB_FT_PATH)libft.a
LIB_PRINTF_A = $(LIB_PRINTF_PATH)libftprintf.a

SRCS_PATH = src/
OBJ_PATH = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJECTS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror -g

all: libft libftprintf $(NAME)

$(NAME): $(OBJ_PATH) $(OBJECTS) $(H_PATH)lemin.h $(LIB_FT_A) $(LIB_PRINTF_A)
	gcc $(FLAGS) $(OBJECTS) -I $(H_PATH) -L $(LIB_FT_PATH) -lft -L $(LIB_PRINTF_PATH) -lftprintf -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJECTS): $(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(H_PATH)lemin.h
	gcc $(FLAGS) -c $< -I $(H_PATH) -I $(LIB_FT_PATH) -I $(LIB_PRINTF_PATH) -o $@

$(LIB_PRINTF_A): libftprintf

$(LIB_FT_A): libft

libft:
	make -C $(LIB_FT_PATH)

libftprintf:
	make -C $(LIB_PRINTF_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make clean -C $(LIB_FT_PATH)
	make clean -C $(LIB_PRINTF_PATH)

fclean: clean
	make fclean -C $(LIB_FT_PATH)
	make fclean -C $(LIB_PRINTF_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft libftprintf