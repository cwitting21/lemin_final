/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:00:11 by fculator          #+#    #+#             */
/*   Updated: 2020/01/27 22:36:50 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ants(t_map *map, char *line)
{
	int			i;
	char		*str;
	long long	d;

	i = 0;
	map->val->part = 1;
	map->in->ants_list = ft_join(map->in->ants_list, line, 0);
	if (line[0] == '#' && line[1] != '#')
		return ;
	str = ft_strtrim(line);
	d = ft_atoi(str);
	if (d <= 0 || d > INT_MAX)
	{
		ft_memdel((void**)&line);
		free_map(map, 1);
	}
	map->ants = d;
	while (str[i] != '\n' && str[i] != 0)
	{
		if (!ft_isdigit(str[i++]))
			free_map(map, 1);
	}
	free(str);
}
