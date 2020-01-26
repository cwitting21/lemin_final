/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 00:45:42 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 22:53:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static void			print_solution(t_solution sol, t_map *map)
// {
// 	int				i = -1;
// 	int				k;
// 	int				c;
// 	t_adj_list_node	*tmp;

// 	printf("\n-----------------SOLUTION-------------------------\n");
// 	while (++i < sol.amount_ways)
// 	{
// 		k = -1;
// 		c = 0;
// 		printf("\nWAY[%d]\n\n", i);
// 		while (++k < map->rooms_count)
// 		{
// 			tmp = sol.ready_ways[i].way[k].head;
// 			if (tmp && tmp->data)
// 			{
// 				printf("[%s] :", map->rooms[k]);
// 				printf(" %s ", map->rooms[tmp->data]);
// 				tmp = tmp->next;
// 				c++;
// 				if (!tmp)
// 					printf("\n");
// 			}
// 		}
// 		printf("---%d lines---\n", c);
// 		printf("%d ants\n", sol.ready_ways[i].amount_ants);
// 	}
// }

// static void			print_ready_ways(t_map *map)
// {
// 	t_adj_list_node	*tmp;
// 	int				i = -1;
// 	int				k;

// 	while (++i < map->r_ways->n) // r_ways[60]
// 	{
// 		printf("-------------------\n");
// 		printf("WAY[%d]\n", i);
// 		k = -1;
// 		if (!map->r_ways[i].deleted)
// 		{
// 			while (++k < map->rooms_count)
// 			{
// 				tmp = map->r_ways[i].way[k].head;
// 				if (tmp)
// 					printf("[%s] :", map->rooms[k]);
// 				if (tmp)
// 				{
// 					printf(" %s ", map->rooms[tmp->data]);
// 					tmp = tmp->next;
// 					if (!tmp)
// 						printf("\n");
// 				}
// 			}
// 		}
// 		else
// 			printf("WAY[%d] is marked as deleted\n", i);
// 	}
// }

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

	if (!(new_way = (t_adj_list*)ft_memalloc(sizeof(t_adj_list) * map->rooms_count)))
		return (NULL);
	map->r_ways->n++;
	return (new_way);
}

static void			get_ready_ways(t_map *map)
{
	int				i;
	t_adj_list_node	*start;
	t_adj_list_node	*del;
	t_adj_list_node	*del_tmp;
	int				tmp;
	int				j;
	int				tmp2;
	int				start_edges[60];
	int				in_way[map->rooms_count];

	i = 0;
	ft_bzero(in_way, map->rooms_count * sizeof(int));
	ft_bzero(&start_edges, sizeof(int) * 60);
	start = map->graph[0].head;
	while (start) 
	{
		tmp2 = 0;
		tmp = start->data;
		map->r_ways[i].way = create_ready_way(map);
		if (tmp == map->rooms_count - 1)
				add_to_ready_way(map, tmp, tmp2, i);
		while (tmp != map->rooms_count - 1)
		{
			if (!in_way[tmp])
			{
				in_way[tmp] = 1;
				add_to_ready_way(map, tmp, tmp2, i);
			}
			else if (in_way[tmp] == 1)
			{
				map->r_ways[i].deleted = 1;
				j = 0;
				while (++j < map->rooms_count)
				{
					del = map->r_ways[i].way[j].head;
					while (del)
					{
						del_tmp = del->next;
						ft_memdel((void**)&del);
					}
				}
				ft_memdel((void**)&map->r_ways[i].way);
				i--;
				map->r_ways->n--;
				break ;
			}
			tmp2 = tmp;
			tmp = map->graph[tmp].head->data;
			if (tmp == map->rooms_count - 1)
				add_to_ready_way(map, tmp, tmp2, i);
		}
		i++;
		start = start->next;
	}
}

void			solve_map(t_map *map)
{
	int			i;
	int			bfs_found_smth = 1;
	t_solution	best_solution;
	t_solution	current_solution;

	i = 0;
	ft_bzero(&current_solution, sizeof(t_solution));
	ft_bzero(&best_solution, sizeof(t_solution));
	if (!(map->graph = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
		exit(1);
	while (bfs_found_smth)
	{
		if (best_solution.amount_lines > current_solution.amount_lines ||
				best_solution.amount_lines == 0)
		{
			best_solution = current_solution; // rewrite with malloc ???
			// free cur sol
		}
		bfs_found_smth = bfs_adj_list(map, i);
		if (bfs_found_smth)
		{
			map->r_ways->n = 0;
			add_one_way(map, i);	// push found way to the new graph
			delete_intersections(map);
			get_ready_ways(map);
			// if (current_solution.amount_lines != 0)
				// del_sol(current_solution, map->rooms_count);
			// ft_bzero(&current_solution, sizeof(t_solution));
			// if (best_solution.amount_ways != current_solution.amount_ways)
			current_solution = distribute_ants(map, map->ants);
			reverse_edges(map, i);
			free_r_ways(map);
		}
		++i;
	}
	move_ants(best_solution, map);
}
