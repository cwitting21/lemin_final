/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:18:20 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/16 22:18:37 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_exit(char *msg)
{
	if (errno)
	{
		perror(msg ? msg : "");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
