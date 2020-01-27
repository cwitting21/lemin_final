/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ready_ways.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:25:26 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:25:30 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_ready_ways(t_map *map)
{
	t_al_node	*tmp;
	int				i = -1;
	int				k;

	while (++i < map->r_ways->n) // r_ways[60]
	{
		printf("-------------------\n");
		printf("WAY[%d]\n", i);
		k = -1;
		if (!map->r_ways[i].deleted)
		{
			while (++k < map->rooms_count)
			{
				tmp = map->r_ways[i].way[k].head;
				if (tmp)
					printf("[%s] :", map->rooms[k]);
				if (tmp)
				{
					printf(" %s ", map->rooms[tmp->data]);
					tmp = tmp->next;
					if (!tmp)
						printf("\n");
				}
			}
		}
		else
			printf("WAY[%d] is marked as deleted\n", i);
	}
}
