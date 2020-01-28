/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ways_to_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:09:29 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 10:09:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		copy_ways_to_sol(t_solution *sol, t_map *map)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	while (++i < map->r_ways->n)
	{
		k = -1;
		sol->rw[j].way = (t_al*)ft_memalloc(map->rooms_count * sizeof(t_al));
		while (++k < map->rooms_count)
		{
			sol->rw[j].way[k].head = (t_al_node*)ft_memalloc(sizeof(t_al_node));
			if (map->r_ways[i].way[k].head)
			{
				sol->rw[j].way[k].head->data = map->r_ways[i].way[k].head->data;
				sol->rw[j].way->rooms_n++;
			}
		}
		j++;
		sol->amount_ways++;
	}
}
