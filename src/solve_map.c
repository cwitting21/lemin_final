/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 00:45:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 20:22:43 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			del_way(t_map *map, int *i)
{
	int				j;
	t_adj_list_node	*del;
	t_adj_list_node	*del_tmp;

	j = 0;
	map->r_ways[(*i)].deleted = 1;
	while (++j < map->rooms_count)
	{
		del = map->r_ways[*i].way[j].head;
		while (del)
		{
			del_tmp = del->next;
			ft_memdel((void**)&del);
		}
	}
	ft_memdel((void**)&map->r_ways[*i].way);
	(*i)--;
	map->r_ways->n--;
}

static void			add_to_ready_way(t_map *map, int to, int from, int way_i)
{
	t_adj_list_node	*new;

	if (!(new = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node))))
		exit(1);
	new->data = to;
	map->r_ways[way_i].way[from].head = new;
	new->next = NULL;
	map->r_ways[way_i].way->rooms_n++;
}

static t_adj_list	*create_ready_way(t_map *map)
{
	t_adj_list		*new_way;

	if (!(new_way = (t_adj_list*)ft_memalloc(sizeof(t_adj_list) *
					map->rooms_count)))
		return (NULL);
	map->r_ways->n++;
	return (new_way);
}

static void			help_func1(int *tmp, int data, t_map *map, int i)
{
	*(tmp + 1) = 0;
	*(tmp) = data;
	map->r_ways[i].way = create_ready_way(map);
	if (tmp[0] == map->rooms_count - 1)
		add_to_ready_way(map, tmp[0], tmp[1], i);
}

static void			help_func2(int *in_way, t_map *map, int *tmp, int i)
{
	*in_way = 1;
	add_to_ready_way(map, tmp[0], tmp[1], i);
}

static void			help_func3(t_map *map, int *tmp, int i)
{
	if (tmp[0] == map->rooms_count - 1)
		add_to_ready_way(map, tmp[0], tmp[1], i);
}

static void			recalculate_data1(int *tmp2, int *tmp, int data)
{
	*tmp2 = *tmp;
	*tmp = data;
}

static void			recalculate_data2(int *i, t_adj_list_node **start)
{
	++(*i);
	*start = (*start)->next;
}

static void			get_ready_ways(t_map *map)
{
	int				i;
	int				tmp[2];
	int				in_way[map->rooms_count];
	t_adj_list_node	*start;

	i = 0;
	ft_bzero(in_way, map->rooms_count * sizeof(int));
	start = map->graph[0].head;
	while (start)
	{
		help_func1(tmp, start->data, map, i);
		while (tmp[0] != map->rooms_count - 1)
		{
			if (!in_way[tmp[0]])
				help_func2(&in_way[tmp[0]], map, tmp, i);
			else if (in_way[tmp[0]] == 1)
			{
				del_way(map, &i);
				break ;
			}
			recalculate_data1(&tmp[1], &tmp[0], map->graph[tmp[0]].head->data);
			help_func3(map, tmp, i);
		}
		recalculate_data2(&i, &start);
	}
}

static void			help_func4(t_solution *best, t_solution cur, int size)
{
	del_sol(*best, size);
	create_best_sol(best, cur, size);
}

void				solve_map(t_map *map)
{
	int				i;
	int				bfs_found_way;
	t_solution		best_sol;
	t_solution		cur_sol;

	i = 0;
	bfs_found_way = 1;
	ft_bzero(&cur_sol, sizeof(t_solution) * 2);
	if (!(map->graph = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
		exit(1);
	while (bfs_found_way)
	{
		if (best_sol.amount_lines > cur_sol.amount_lines || best_sol.amount_lines == 0)
			help_func4(&best_sol, cur_sol, map->rooms_count);
		if ((bfs_found_way = bfs_adj_list(map, i)))
		{
			map->r_ways->n = 0;
			map->r_ways->n_del = 0;
			add_one_way(map, i);
			delete_intersections(map);
			get_ready_ways(map);
			del_sol(cur_sol, map->rooms_count);
			cur_sol = distribute_ants(map, map->ants);
			reverse_edges(map, i);
			free_r_ways(map);
		}
		++i;
	}
	move_ants(best_sol, map);
	del_sol(cur_sol, map->rooms_count);
	del_sol(best_sol, map->rooms_count);
}
