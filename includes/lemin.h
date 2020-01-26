/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:58 by fculator          #+#    #+#             */
/*   Updated: 2020/01/22 22:43:39 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// REMOVE!!!
#include <stdio.h>

// # include "../libprintf/includes/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include "libft.h"
# include "libftprintf.h"

typedef enum    e_bool
{
    True = 1,
    False = !True
}               t_bool;

typedef struct	s_valid
{
	int			part;
	int			good[2];
	int			new_line;
	int			init_2;
}				t_valid;

typedef struct 	s_input
{
	char		*rooms_list;
	char		*ants_list;
	char		*link_list;
	// char		**refact_split; // test
}				t_input;

typedef struct	s_adj_list_node
{
	int						data;
	// t_bool					dup;
	struct s_adj_list_node	*next;
}				t_adj_list_node;

typedef struct	s_adj_list
{
	t_adj_list_node			*head;
	// t_adj_list_node			*in;
	// t_adj_list_node			*out;
	int						rooms_n; // number of rooms in a way
}				t_adj_list;

typedef struct	s_ways
{
	t_adj_list	*way;
	int			n; // number of ways
	int			deleted;
	int			amount_ants;
}				t_ways;

typedef struct	s_map
{
	char		**rooms;
	int			rooms_count;
	int			ants;
	int			curr_room;
	int			w_ind;
	int			*way;
	int			**matrix;
	t_valid		*val;
	t_input 	*in;
	int			*in_way;
	t_adj_list	*array;		// adjacency list. initial graph
	t_adj_list	*graph;		// adjacency list. end graph
	t_ways		*ways;		// stores all found ways
	t_ways		r_ways[60];	// ready ways
	t_bool		dup_arr[10000]; // change 100 later. array of room indexes that are duplicated
}				t_map;

typedef struct	s_solution
{
	t_ways		ready_ways[60];
	int			amount_ways;
	int			good_ways;
	int			amount_lines;
}				t_solution;

typedef struct	s_qnode
{
	int				data;
	struct s_qnode	*next;
}				t_qnode;

typedef struct	s_q
{
	t_qnode		*head;
	t_qnode		*end;
}				t_q;

typedef	struct	s_ants
{
	int			*arr;
}				t_ants;

int				get_next_line(const int fd, char **line);
void			initialize_map(t_map *map);
void			free_map(t_map *map, int code);
void			free_array(char **array, t_map *m, int code);
void			parse_map_to_struct(t_map *map);
void			ants(t_map *map, char *line);
void			add_room_list(t_map *map,char *line);
void			room_table(t_map *m);
int				is_empty(char *s);
void			add_link_list(t_map *map, char *line);
void			validate_room(t_map *m, char *line);
void			is_number(char **r, t_map *m, char *s);
void			initialize_map_2(t_map *map);
void			validate_link(t_map *m, char *link);
void			connectivity_matrix(t_map *m);
int				room_index(t_map *m, char *room_name, int start);
void			good(t_map *m, char **line, char **r, int end);
void			check_start_end(t_map *m, char **r, int end);
void			is_valid(t_map *m, int i, char **r);
void			bfs(t_map *map);
void			part_validation_map(t_map *map);
void			matrix_to_adj_list(t_map *map);
int				bfs_adj_list(t_map *map, int way_i);
void			reverse_edges(t_map *map, int i);
t_adj_list_node	*add_to_way(t_ways *ways, int from, int to, int way_i);
void			ft_exit(char *msg);
void			print_adj_list(t_map *map);
void		    print_matrix(t_map *m);
void			push_q(t_q *q, int index);
int				pop_q(t_q *q);
int				empty_q(t_q *q);
void			print_parents(t_map *map, int *parent);
void			print_shortest_path(t_map *map, int *parent, int i);
void			create_way(t_map *map, int i, int *parent, int way_i);
void			print_way(t_map *map, int way_i);
// void			duplicate_rooms(t_map *map);
void			print_name_index(t_map *map);
void			free_all(t_map *map);
void			print_map(t_map *map);
void			bfs_2(t_map *map);
void			add_ways_to_graph(t_map *map);
void			solve_map(t_map *map);
void			add_one_way(t_map *map, int way_i);
void			delete_intersections(t_map *map);
void			print_graph(t_map *map);
t_solution		distribute_ants(t_map *map, int ants_n);
void			del_q(t_q *q);
void			move_ants(t_solution sol, t_map *map);
void			free_r_ways(t_map *map);
void			del_sol(t_solution sol, int rooms_n);
void			part_validation_map_2(t_map *map);

# endif
