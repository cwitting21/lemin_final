/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:46:35 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/17 13:46:37 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(t_map *map)
{
	ft_putendl(map->in->ants_list);
	ft_putendl(map->in->rooms_list);
	ft_putendl(map->in->link_list);
	ft_putchar('\n');
}
