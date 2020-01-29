/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:09:16 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 17:18:59 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_way(t_map *map, int way_i)
{
	int			k;
	int			i;
	t_al_node	*tmp;

	k = -1;
	i = 0;
	ft_printf("\nWAY[%d]\n", way_i);
	while (++k < map->rooms_count)
	{
		tmp = map->ways[way_i].way[k].head;
		if (tmp)
			ft_printf("[%s] :", map->rooms[k]);
		if (tmp)
		{
			ft_printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
			if (!tmp)
			{
				ft_printf("k = %d  ", k);
				ft_printf("\n");
				++i;
			}
		}
	}
	ft_printf("\n%d lines\n", i);
}
