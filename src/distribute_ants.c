/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:07:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 18:11:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_amount_lines(t_solution *sol)
{
	sol->amount_lines = (sol->ready_ways[0].way->rooms_n - 1) +
		(sol->ready_ways[0].amount_ants - 1);
}

static void		copy_ways_to_sol_malloc(t_solution *sol, t_map *map)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	while (++i < map->r_ways->n)
	{
		k = -1;
		// if (!map->r_ways[i].deleted)
		// {
			sol->ready_ways[j].way = (t_adj_list*)ft_memalloc(map->rooms_count * sizeof(t_adj_list));
			while (++k < map->rooms_count)
			{
				sol->ready_ways[j].way[k].head = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node));
				if (map->r_ways[i].way[k].head)
				{
					sol->ready_ways[j].way[k].head->data = map->r_ways[i].way[k].head->data;
					sol->ready_ways[j].way->rooms_n++;
				}
			}
			j++;
			sol->amount_ways++;
		// }
	}
}

t_solution		distribute_ants(t_map *map, int ants_n)
{
	t_solution	sol;
	int			ways_n;
	int			i;
	int			max;
	int			sum;

	ft_bzero(&sol, sizeof(t_solution));
	copy_ways_to_sol_malloc(&sol, map);
	ways_n = 1;
	if (ways_n >= sol.amount_ways)
    	max = sol.ready_ways[0].way->rooms_n - 1;
	else
		max = sol.ready_ways[ways_n].way->rooms_n - 1;
	while (ants_n != 0 && ways_n <= sol.amount_ways)
	{
		i = 0;
		while (i < ways_n && ants_n != 0)
		{
			sum = sol.ready_ways[i].way->rooms_n - 1 + 
						sol.ready_ways[i].amount_ants;
			if (sum < max)
			{
				// recalculate(&sum, &ants_n, &);
				++sol.ready_ways[i].amount_ants;
				++sum;
				--ants_n;
			}
			if (++i >= ways_n && sum < max)
				i = 0;
		}
		ways_n++;
		if (ways_n >= sol.amount_ways)
		{
			++max;
			if (ways_n > sol.amount_ways)
				--ways_n;
		}
		else
			max = sol.ready_ways[ways_n].n - 1;
	}
	get_amount_lines(&sol);
	return (sol);
}
