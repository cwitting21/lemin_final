/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:15:43 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 08:59:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				print_solution(t_solution sol, t_map *map)
{
	int				i[3];
	t_al_node		*tmp;

	i[0] = -1;
	printf("\n-----------------SOLUTION-------------------------\n");
	while (++i[0] < sol.amount_ways)
	{
		i[1] = -1;
		i[2] = 0;
		printf("\nWAY[%d]\n\n", i[0]);
		while (++i[1] < map->rooms_count)
		{
			tmp = sol.rw[i[0]].way[i[1]].head;
			if (tmp && tmp->data)
			{
				printf("[%s] : %s ", map->rooms[i[1]], map->rooms[tmp->data]);
				tmp = tmp->next;
				i[2]++;
				if (!tmp)
					printf("\n");
			}
		}
		printf("---%d lines---\n", i[2]);
		printf("%d ants\n", sol.rw[i[0]].amount_ants);
	}
}
