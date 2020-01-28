/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:09:16 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 08:38:25 by cwitting         ###   ########.fr       */
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
	printf("\nWAY[%d]\n", way_i);
	while (++k < map->rooms_count)
	{
		tmp = map->ways[way_i].way[k].head;
		if (tmp)
			printf("[%s] :", map->rooms[k]);
		if (tmp)
		{
			printf(" %s ", map->rooms[tmp->data]);
			tmp = tmp->next;
			if (!tmp)
			{
				printf("k = %d  ", k);
				printf("\n");
				++i;
			}
		}
	}
	printf("\n%d lines\n", i);
}
