/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_one_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:55:22 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/22 01:42:44 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			create_node(t_map *map, int from, int to)
{
	t_adj_list_node	*new;
	t_adj_list_node		*tmp;
	t_adj_list_node		*prev;

	if (!(new = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node))))
		exit(1);
	// new->data = to;
	// new->next = map->graph[from].head;
	// map->graph[from].head = new;
	new->data = to;
	if (!map->graph[from].head)
		map->graph[from].head = new;
	else
	{
		tmp = map->graph[from].head;
		prev = tmp;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = new;
		new->next = NULL;
	}
}

void				add_one_way(t_map *map, int way_i)
{
	t_adj_list_node	*tmp;
	int				i;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[way_i].way[i].head;
		if (tmp)
			create_node(map, i, tmp->data);
	}
}
