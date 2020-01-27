/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:03:02 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:04:10 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			del_way(t_map *map, int *i)
{
	int			j;
	t_al_node	*del;
	t_al_node	*del_tmp;

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
