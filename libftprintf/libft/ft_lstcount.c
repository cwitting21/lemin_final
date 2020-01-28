/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:28:41 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 13:28:41 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *lst)
{
	long int count;

	if (lst)
	{
		count = 0;
		while (lst)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	return (0);
}
