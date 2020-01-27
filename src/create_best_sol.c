/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_best_sol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:38:07 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 21:22:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		create_best_sol(t_solution *best, t_solution cur, int size)
{
	int		i;
	int		k;

	i = -1;
	best->lines_n = cur.lines_n;
	best->amount_ways = cur.amount_ways;
	best->good_ways = cur.good_ways;
	while (++i < cur.amount_ways)
	{
		best->rw[i].way = (t_al*)ft_memalloc(sizeof(t_al) * size);
		best->rw[i].amount_ants = cur.rw[i].amount_ants;
		best->rw[i].n = cur.rw[i].n;
		best->rw[i].deleted = cur.rw[i].deleted;
		k = -1;
		while (++k < size)
		{
			best->rw[i].way[k].head = (t_al_node*)ft_memalloc(sizeof(t_al_node));
			best->rw[i].way[k].rooms_n = cur.rw[i].way[k].rooms_n;
			best->rw[i].way[k].head->data = cur.rw[i].way[k].head->data;
			best->rw[i].way[k].head->next = cur.rw[i].way[k].head->next;
		}
	}
}
