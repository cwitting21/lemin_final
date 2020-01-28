/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 00:45:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 21:11:53 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			help_func1(int *tmp, int data, t_map *map, int i)
{
	*(tmp + 1) = 0;
	*(tmp) = data;
	map->r_ways[i].way = create_ready_way(map);
	if (tmp[0] == map->rooms_count - 1)
		add_to_ready_way(map, tmp[0], tmp[1], i);
}

static void			get_ready_ways(t_map *map)
{
	int				i;
	int				tmp[2];
	int				in_way[map->rooms_count];
	t_al_node		*start;

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

static void			help_func5(t_map *map, int i, t_solution cur_sol)
{
	map->r_ways->n = 0;
	add_one_way(map, i);
	delete_intersections(map);
	get_ready_ways(map);
	del_sol(cur_sol, map->rooms_count);
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

	init_data1(&i, &bfs_found_way);
	ft_bzero(&cur_sol, sizeof(t_solution) * 2);
	if (!(map->graph = (t_al*)ft_memalloc(map->rooms_count * sizeof(t_al))))
		exit(1);
	while (bfs_found_way)
	{
		if (best_sol.lines_n > cur_sol.lines_n || best_sol.lines_n == 0)
			help_func4(&best_sol, cur_sol, map->rooms_count);
		if ((bfs_found_way = bfs_adj_list(map, i)))
		{
			help_func5(map, i, cur_sol);
			cur_sol = distribute_ants(map, map->ants);
			reverse_edges(map, i);
			free_ready_ways(map);
		}
		++i;
	}
	move_ants(best_sol, map);
	del_sol(cur_sol, map->rooms_count);
	del_sol(best_sol, map->rooms_count);
}
