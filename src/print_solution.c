/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:15:43 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/26 23:15:59 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				print_solution(t_solution sol, t_map *map)
{
	int				i = -1;
	int				k;
	int				c;
	t_adj_list_node	*tmp;

	printf("\n-----------------SOLUTION-------------------------\n");
	while (++i < sol.amount_ways)
	{
		k = -1;
		c = 0;
		printf("\nWAY[%d]\n\n", i);
		while (++k < map->rooms_count)
		{
			tmp = sol.ready_ways[i].way[k].head;
			if (tmp && tmp->data)
			{
				printf("[%s] :", map->rooms[k]);
				printf(" %s ", map->rooms[tmp->data]);
				tmp = tmp->next;
				c++;
				if (!tmp)
					printf("\n");
			}
		}
		printf("---%d lines---\n", c);
		printf("%d ants\n", sol.ready_ways[i].amount_ants);
	}
}
