/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_r_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:32:23 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 23:03:20 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				free_r_ways(t_map *map)
{
	t_adj_list_node	*del;
	t_adj_list_node	*tmp;
	int				i;
	int				k;

	i = -1;
	while (++i < map->ways->n)
	{
		if (map->r_ways[i].way)
		{
			k = -1;
			while (++k < map->rooms_count)
			{
				tmp = map->r_ways[i].way[k].head;
				if (tmp)
				{
					del = tmp;
					tmp = tmp->next;
					ft_memdel((void**)&del);
				}
				// ft_memdel((void**)&map->r_ways[i].way);
			}
			ft_memdel((void**)&map->r_ways[i].way);
		}
	}
}
