/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_ready_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:01:07 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:01:37 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			add_to_ready_way(t_map *map, int to, int from, int way_i)
{
	t_al_node	*new;

	if (!(new = (t_al_node*)ft_memalloc(sizeof(t_al_node))))
		exit(1);
	new->data = to;
	map->r_ways[way_i].way[from].head = new;
	new->next = NULL;
	map->r_ways[way_i].way->rooms_n++;
}
