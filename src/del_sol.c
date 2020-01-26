/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:42:11 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/22 19:44:49 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				del_sol(t_solution sol, int rooms_n)
{
	int				del_i;
	int				k;
	t_adj_list_node	*tmp;
	t_adj_list_node	*del;


	del_i = -1;
	while (++del_i < sol.amount_ways)
	{
		k = -1;
		while (++k < rooms_n)
		{
			tmp = sol.ready_ways[del_i].way[k].head;
			while (tmp)
			{
				del = tmp;
				tmp = tmp->next;
				ft_memdel((void**)&del);
			}
		}
		ft_memdel((void**)&sol.ready_ways[del_i]);
	}
	ft_memdel((void**)&sol);
}
