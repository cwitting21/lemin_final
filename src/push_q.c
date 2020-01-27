/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:17:17 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:33:00 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		push_q(t_q *q, int index)
{
	t_qnode		*new;

	if (!(new = (t_qnode*)ft_memalloc(sizeof(t_qnode))))
		ft_exit("bfs/push_q");
	new->data = index;
	if (!q->head)
	{
		q->head = new;
		q->end = new;
		new->next = NULL;
	}
	else if (q->head && q->head == q->end)
	{
		q->head->next = new;
		q->end = new;
		new->next = NULL;
	}
	else
	{
		q->end->next = new;
		q->end = new;
	}
}
