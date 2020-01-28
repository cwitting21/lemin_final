/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_q.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:18:21 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/27 22:47:56 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		pop_q(t_q *q)
{
	t_qnode		*del;
	int			i;

	i = 0;
	del = NULL;
	if (!q->head || !q->end)
		ft_exit("pop_q");
	else if (q->head && q->head == q->end)
	{
		i = q->head->data;
		ft_memdel((void**)&q->head);
		q->end = NULL;
	}
	else
	{
		i = q->head->data;
		del = q->head;
		q->head = q->head->next;
		ft_memdel((void**)&del);
	}
	return (i);
}
