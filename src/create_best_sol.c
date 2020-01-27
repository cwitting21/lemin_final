/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_best_sol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:38:07 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 05:51:53 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		create_best_sol(t_solution *best, t_solution cur, int size)
{
	int		i;
	int		k;

	i = -1;
	best->amount_lines = cur.amount_lines;
	best->amount_ways = cur.amount_ways;
	best->good_ways = cur.good_ways;
	while (++i < cur.amount_ways)
	{
		best->ready_ways[i].way = (t_adj_list*)ft_memalloc(sizeof(t_adj_list) * size);
		best->ready_ways[i].amount_ants = cur.ready_ways[i].amount_ants;
		best->ready_ways[i].n = cur.ready_ways[i].n;
		best->ready_ways[i].deleted = cur.ready_ways[i].deleted;
		k = -1;
		while (++k < size)
		{
			best->ready_ways[i].way[k].head = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node));
			best->ready_ways[i].way[k].rooms_n = cur.ready_ways[i].way[k].rooms_n;
			best->ready_ways[i].way[k].head->data = cur.ready_ways[i].way[k].head->data;
			best->ready_ways[i].way[k].head->next = cur.ready_ways[i].way[k].head->next;
		}
	}
}
