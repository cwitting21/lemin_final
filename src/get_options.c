/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:25:55 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/28 14:47:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		get_options(t_map *map, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp("-lines", av[i]) == 0)
			map->options[0] = 1;
		else if (ft_strcmp("-list", av[i]) == 0)
			map->options[1] = 1;
		else
		{
			ft_printf("Incorrect option\n");
			exit(1);
		}
	}
}
