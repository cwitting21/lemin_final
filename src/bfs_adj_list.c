/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_adj_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 06:54:54 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 22:47:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			bfs_adj_list(t_map *map, int way_i)
{
	t_adj_list_node	*tmp;
	int		i = 0;
	int		visited[10000];
	int		parent[10000];
	t_q		q;

	ft_bzero(visited, 10000 * sizeof(int));
	ft_bzero(parent, 10000 * sizeof(int));
	ft_bzero(&q, sizeof(t_q));
	push_q(&q, 0); // add start node
	visited[0] = 1;
	while (!empty_q(&q) && i != map->rooms_count - 1)
	{
		i = pop_q(&q);
		tmp = map->array[i].head;
		while (tmp)
		{
			if (!visited[tmp->data])
			{
				visited[tmp->data] = 1;
				push_q(&q, tmp->data);
				parent[tmp->data] = i;
			}
			tmp = tmp->next;
		}
	}
	del_q(&q);
	if (i == map->rooms_count - 1)
	{
		if (!(map->ways[way_i].way = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list))))
			ft_exit("ways->way");;
		create_way(map, i, parent, way_i);
		map->ways->n++;
		return (1);
	}
	return (0);
}
