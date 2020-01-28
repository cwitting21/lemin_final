/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:58 by fculator          #+#    #+#             */
/*   Updated: 2020/01/28 11:31:22 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include "libft.h"
# include "../libftprintf/libftprintf.h"

/*
** t_al - adjacency list
** t_al_node - adjacency list node
** rw - ready_ways
*/

typedef struct	s_valid
{
	int			part;
	int			good[2];
	int			new_line;
	int			init_2;
}				t_valid;

typedef struct	s_input
{
	char		*rooms_list;
	char		*ants_list;
	char		*link_list;
}				t_input;

typedef struct	s_al_node
{
	int						data;
	struct s_al_node		*next;
}				t_al_node;

/*
**	rooms_n - number of rooms in a way
*/

typedef struct	s_al
{
	t_al_node	*head;
	int			rooms_n;
}				t_al;

/*
**	n - number of ways
*/

typedef struct	s_ways
{
	t_al		*way;
	int			n;
	int			deleted;
	int			amount_ants;
}				t_ways;

/*
**	array - adjacency list. initial graph
**	graph - adjacency list. end graph
**	ways - stores all found ways
**	r_ways - ready ways
*/

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
	t_input		*in;
	int			*in_way;
	t_al		*array;
	t_al		*graph;
	t_ways		*ways;
	t_ways		r_ways[60];
}				t_map;

typedef struct	s_solution
{
	t_ways		rw[60];
	int			amount_ways;
	int			good_ways;
	int			lines_n;
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

typedef struct	s_ants
{
	int			*ants_room;
	int			*ants_way;
	int			*occ_room;
}				t_ants;

int				get_next_line(const int fd, char **line);
void			initialize_map(t_map *map);
void			free_map(t_map *map, int code);
void			free_array(char **array, t_map *m, int code);
void			parse_map_to_struct(t_map *map);
void			ants(t_map *map, char *line);
void			add_room_list(t_map *map, char *line);
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
void			part_validation_map(t_map *map);
void			matrix_to_adj_list(t_map *map);
int				bfs_adj_list(t_map *map, int way_i);
void			reverse_edges(t_map *map, int i);
t_al_node		*add_to_way(t_ways *ways, int from, int to, int way_i);
void			ft_exit(char *msg);
void			print_adj_list(t_map *map);
void			print_matrix(t_map *m);
void			push_q(t_q *q, int index);
int				pop_q(t_q *q);
int				empty_q(t_q *q);
void			print_parents(t_map *map, int *parent);
void			print_shortest_path(t_map *map, int *parent, int i);
void			create_way(t_map *map, int i, int *parent, int way_i);
void			print_way(t_map *map, int way_i);
void			print_name_index(t_map *map);
void			free_all(t_map *map);
void			print_map(t_map *map);
void			solve_map(t_map *map);
void			add_one_way(t_map *map, int way_i);
void			delete_intersections(t_map *map);
void			print_graph(t_map *map);
t_solution		distribute_ants(t_map *map, int ants_n);
void			del_q(t_q *q);
void			move_ants(t_solution sol, t_map *map);
void			free_ready_ways(t_map *map);
void			del_sol(t_solution sol, int rooms_n);
void			part_validation_map_2(t_map *map);
void			print_ready_ways(t_map *map);
void			print_solution(t_solution sol, t_map *map);
void			create_best_sol(t_solution *best, t_solution cur, int size);
void			init_data1(int *i, int *bfs_found_way);
void			help_func2(int *in_way, t_map *map, int *tmp, int i);
void			help_func3(t_map *map, int *tmp, int i);
void			recalculate_data1(int *tmp2, int *tmp, int data);
void			recalculate_data2(int *i, t_al_node **start);
t_al			*create_ready_way(t_map *map);
void			add_to_ready_way(t_map *map, int to, int from, int way_i);
void			del_way(t_map *map, int *i);
void			set_ways(int *ants_way, t_solution sol, int size);
void			copy_ways_to_sol(t_solution *sol, t_map *map);

#endif
