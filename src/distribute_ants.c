/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:07:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/01/29 21:24:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_lines_n(t_solution *sol)
{
	sol->lines_n = (sol->rw[0].way->rooms_n - 1) +
		(sol->rw[0].amount_ants - 1);
}

static void		norm_func1(int *sum, int *sol_ants_n, int *ants_n, int max)
{
	if (*sum < max)
	{
		++(*sol_ants_n);
		++(*sum);
		--(*ants_n);
	}
}

static void		norm_func2(int *i, int ways_n, int sum, int max)
{
	if (++(*i) >= ways_n && sum < max)
		*i = 0;
}

static void		norm_func3(int *max, int *ways_n, int sol_ways_n)
{
	++(*max);
	if (*ways_n > sol_ways_n)
		--(*ways_n);
}

/*
**	i - i[0]
**	max - i[1]
**	sum - i[2]
*/

t_solution		distribute_ants(t_map *map, int ants_n)
{
	t_solution	sol;
	int			ways_n;
	int			i[3];

	ft_bzero(&sol, sizeof(t_solution));
	copy_ways_to_sol(&sol, map);
	ways_n = 1;
	i[1] = (ways_n >= sol.amount_ways ? sol.rw[0].way->rooms_n - 1 :
										sol.rw[ways_n].way->rooms_n - 1);
	while (ants_n != 0)
	{
		i[0] = 0;
		while (i[0] < ways_n && ants_n != 0)
		{
			i[2] = sol.rw[i[0]].way->rooms_n - 1 + sol.rw[i[0]].amount_ants;
			norm_func1(&i[2], &sol.rw[i[0]].amount_ants, &ants_n, i[1]);
			norm_func2(&i[0], ways_n, i[2], i[1]);
		}
		if (++ways_n >= sol.amount_ways)
			norm_func3(&i[1], &ways_n, sol.amount_ways);
		else
			i[1] = sol.rw[ways_n].n - 1;
	}
	get_lines_n(&sol);
	return (sol);
}
