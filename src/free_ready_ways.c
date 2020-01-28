/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ready_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:32:23 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 19:04:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_ready_ways(t_map *map)
{
	t_al		*way_del;
	// t_al_node	*del;
	// t_al_node	*tmp;
	int			i;
	int			k;

	i = -1;
	while (++i < map->r_ways->n)
	{
		way_del = map->r_ways[i].way;
		k = -1;
		while (++k < map->rooms_count)
		{
			ft_memdel((void**)&map->r_ways[i].way[k].head);
			// while (tmp)
			// {
				// del = tmp;
				// tmp = tmp->next;
				// ft_memdel((void**)&del);
				// free(del);
				// del = NULL;
			// }
		}
		ft_memdel((void**)&map->r_ways[i]);
		ft_memdel((void**)&map->r_ways[i].way);
	}
}
