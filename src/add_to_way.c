/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:16:31 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/21 03:44:25 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_adj_list_node			*add_to_way(t_ways *ways, int from, int to, int way_i)
{
	t_adj_list_node		*new;
	t_adj_list_node		*tmp;
	t_adj_list_node		*prev;

	if (!(new = (t_adj_list_node*)ft_memalloc(sizeof(t_adj_list_node))))
		return (NULL);
	new->data = to;
	if (!ways[way_i].way[from].head)
		ways[way_i].way[from].head = new;
	else
	{
		tmp = ways[way_i].way[from].head;
		prev = tmp;
		while (tmp && tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = new;
		new->next = NULL;
	}
	return (new);
}
