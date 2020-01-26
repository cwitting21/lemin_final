/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ready_ways.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:14:48 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 23:15:03 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_ready_ways(t_map *map)
{
	t_adj_list_node	*tmp;
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
