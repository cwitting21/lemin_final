/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:42:11 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:44:30 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			del_sol(t_solution sol, int rooms_n)
{
	int			del_i;
	int			k;
	t_al_node	*tmp;
	t_al_node	*del;

	del_i = -1;
	while (++del_i < sol.amount_ways)
	{
		k = -1;
		while (++k < rooms_n)
		{
			tmp = sol.rw[del_i].way[k].head;
			while (tmp)
			{
				del = tmp;
				tmp = tmp->next;
				ft_memdel((void**)&del);
			}
		}
		ft_memdel((void**)&sol.rw[del_i]);
	}
	ft_memdel((void**)&sol);
}
