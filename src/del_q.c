/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_q.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:16:18 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/21 01:16:26 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_q(t_q *q)
{
	t_qnode	*q_node;
	t_qnode	*del;

	q_node = q->head;
	while (q_node)
	{
		del = q_node;
		q_node = q_node->next;
		ft_memdel((void**)&del);
	}
}
