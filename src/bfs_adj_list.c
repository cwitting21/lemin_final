/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_adj_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 06:54:54 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:39:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				bfs_adj_list(t_map *map, int way_i)
{
	t_al_node	*tmp;
	int			i;
	int			visited[10000];
	int			parent[10000];
	t_q			q;

	// ft_bzero(visited, 10000 * sizeof(int) * 2);
	ft_bzero(parent, 10000 * sizeof(int) * 2);
	ft_bzero(&q, sizeof(t_q));
	push_q(&q, 0);
	i = 0;
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
		if (!(map->ways[way_i].way = (t_al*)ft_memalloc(sizeof(t_al) * map->rooms_count)))
			ft_exit("ways->way");
		create_way(map, i, parent, way_i);
		map->ways->n++;
		return (1);
	}
	return (0);
}
