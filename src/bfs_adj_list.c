/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_adj_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 06:54:54 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 13:25:50 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		help_func3_local(t_map *map, int way_i, int *parent, int i)
{
	if (i == map->rooms_count - 1)
	{
		if (!(map->ways[way_i].way = (t_al*)ft_memalloc(sizeof(t_al)
												* map->rooms_count)))
			ft_exit("ways->way");
		create_way(map, i, parent, way_i);
		map->ways->n++;
		return (1);
	}
	return (0);
}

static void		help_func2_local(int *visited, int *parent, t_al_node *tmp,
																		int i)
{
	visited[tmp->data] = 1;
	parent[tmp->data] = i;
}

static void		init_data1_local(int *a, int *b)
{
	*a = 0;
	*b = 1;
}

static void		init_data2_local(int *i, t_al_node **tmp, t_q *q, t_map *map)
{
	*i = pop_q(q);
	*tmp = map->array[*i].head;
}

int				bfs_adj_list(t_map *map, int way_i)
{
	t_al_node	*tmp;
	int			i;
	t_q			q;
	int			visited[10000];
	int			parent[10000];

	ft_bzero(parent, 10000 * sizeof(int) * 2);
	ft_bzero(&q, sizeof(t_q));
	push_q(&q, 0);
	init_data1_local(&i, &visited[0]);
	while (!empty_q(&q) && i != map->rooms_count - 1)
	{
		init_data2_local(&i, &tmp, &q, map);
		while (tmp)
		{
			if (!visited[tmp->data])
			{
				help_func2_local(visited, parent, tmp, i);
				push_q(&q, tmp->data);
			}
			tmp = tmp->next;
		}
	}
	del_q(&q);
	return (help_func3_local(map, way_i, parent, i));
}
