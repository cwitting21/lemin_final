/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ready_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:00:23 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:01:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_al		*create_ready_way(t_map *map)
{
	t_al		*new_way;

	if (!(new_way = (t_al*)ft_memalloc(sizeof(t_al) *
					map->rooms_count)))
		return (NULL);
	map->r_ways->n++;
	return (new_way);
}
