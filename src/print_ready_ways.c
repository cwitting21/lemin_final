/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ready_ways.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:25:26 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 08:59:30 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_ready_ways(t_map *map)
{
	t_al_node	*tmp;
	int			i[2];

	i[0] = -1;
	while (++i[0] < map->r_ways->n)
	{
		printf("-------------------\nWAY[%d]\n", i[0]);
		i[1] = -1;
		if (!map->r_ways[i[0]].deleted)
		{
			while (++i[1] < map->rooms_count)
			{
				tmp = map->r_ways[i[0]].way[i[1]].head;
				if (tmp)
				{
					printf("[%s] : %s ", map->rooms[i[1]],
											map->rooms[tmp->data]);
					tmp = tmp->next;
					if (!tmp)
						printf("\n");
				}
			}
		}
		else
			printf("WAY[%d] is marked as deleted\n", i[0]);
	}
}
