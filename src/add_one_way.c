/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_one_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:55:22 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:36:23 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			create_node(t_map *map, int from, int to)
{
	t_al_node		*new;
	t_al_node		*tmp;
	t_al_node		*prev;

	if (!(new = (t_al_node*)ft_memalloc(sizeof(t_al_node))))
		exit(1);
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
	t_al_node		*tmp;
	int				i;

	i = -1;
	while (++i < map->rooms_count)
	{
		tmp = map->ways[way_i].way[i].head;
		if (tmp)
			create_node(map, i, tmp->data);
	}
}
