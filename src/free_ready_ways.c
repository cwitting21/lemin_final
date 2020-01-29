/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ready_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:32:23 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 09:46:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_ready_ways(t_map *map)
{
	int			i;
	int			k;

	i = -1;
	while (++i < map->r_ways->n)
	{
		k = -1;
		while (++k < map->rooms_count)
			ft_memdel((void**)&map->r_ways[i].way[k].head);
		ft_memdel((void**)&map->r_ways[i].way);
	}
}
