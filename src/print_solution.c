/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:15:43 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:22:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				print_solution(t_solution sol, t_map *map)
{
	int				i = -1;
	int				k;
	int				c;
	t_al_node		*tmp;

	printf("\n-----------------SOLUTION-------------------------\n");
	while (++i < sol.amount_ways)
	{
		k = -1;
		c = 0;
		printf("\nWAY[%d]\n\n", i);
		while (++k < map->rooms_count)
		{
			tmp = sol.rw[i].way[k].head;
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
		printf("%d ants\n", sol.rw[i].amount_ants);
	}
}
