/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:00:11 by fculator          #+#    #+#             */
/*   Updated: 2020/01/11 19:46:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ants(t_map *map, char *line)
{
	int		i;
	char	*str;

	i = 0;
	map->val->part = 1;
	map->in->ants_list = ft_join(map->in->ants_list, line, 0);
	if (line[0] == '#')
		return ;
	str = ft_strtrim(line);
	if ((map->ants = ft_atoi(str)) <= 0)
		free_map(map, 1);
	while (str[i] != '\n' && str[i] != 0)
	{
		if (!ft_isdigit(str[i++]))
			free_map(map, 1);
	}
	free(str);
}