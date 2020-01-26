/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:27:51 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/20 03:15:08 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static void	del_q(t_q *q)
// {
// 	t_qnode	*q_node;
// 	t_qnode	*del;

// 	q_node = q->head;
// 	while (q_node)
// 	{
// 		del = q_node;
// 		q_node = q_node->next;
// 		ft_memdel((void**)&del);
// 	}
// }

// void		bfs_2(t_map *map)
// {
// 	t_adj_list_node	*tmp;
// 	int		i = 0;
// 	int		visited[10000];
// 	int		parent[10000];
// 	t_q		q;

// 	ft_bzero(visited, 10000 * 4);
// 	ft_bzero(parent, 10000 * 4);
// 	ft_bzero(&q, sizeof(t_q));
// 	push_q(&q, 0); // add start node
// 	visited[0] = 1;
// 	while (!empty_q(&q) && i != map->rooms_count - 1)
// 	{
// 		i = pop_q(&q);
// 		tmp = map->array[i].head;
// 		while (tmp)
// 		{
// 			if (!visited[tmp->data])
// 			{
// 				visited[tmp->data] = 1;
// 				push_q(&q, tmp->data);
// 				parent[tmp->data] = i;
// 			}
// 			tmp = tmp->next;
// 		}
// 	}
// 	del_q(&q);
// 	// print_parents(map, parent);
// 	if (!(map->ways[1].way = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
// 		ft_exit("ways->way");
// 	// print_shortest_path(map, parent, i);
// 	add_path(map, i, parent, 1);
// 	map->ways->n++;
// 	print_way(map, 1, "SECOND WAY");
// }