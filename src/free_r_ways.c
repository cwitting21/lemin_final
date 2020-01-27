/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_r_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:32:23 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 04:35:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				free_r_ways(t_map *map)
{
	t_adj_list		*way_del;
	t_adj_list_node	*del;
	t_adj_list_node	*tmp;
	int				i;
	int				k;

	i = -1;
	while (++i < map->r_ways->n)
	{
		way_del = map->r_ways[i].way;
		k = -1;
		while (++k < map->rooms_count)
		{
			tmp = map->r_ways[i].way[k].head;
			while (tmp)
			{
				del = tmp;
				tmp = tmp->next;
				ft_memdel((void**)&del);
			}
		}
		ft_memdel((void**)&way_del);
	}
}
