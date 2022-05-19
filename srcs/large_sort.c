/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:46:36 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 18:38:13 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_nbr(t_nbrs *nbrs)
{
	int	i;
	int	temp;
	int	temp2;

	i = 0;
	temp = 1000;
	while (i < nbrs->a_c)
	{
		if (nbrs->mv[i][4] < temp)
		{
			temp2 = i;
			temp = nbrs->mv[i][4];
		}
		i++;
	}
	nbrs->selected = temp2;
}

void	large_sort(t_nbrs *nbrs, int i, int j)
{
	pb(nbrs, 0);
	pb(nbrs, 0);
	while (nbrs->a_state[3])
	{
		actual_positions(nbrs, 0, 0, 0);
		select_nbr(nbrs);
		apply_moves(nbrs);
		pb(nbrs, 0);
	}
	reset_to_big(nbrs);
	if (!check(nbrs, 1))
		three_sort(nbrs);
	while (i < nbrs->total_nbrs)
	{
		if (j < 3 && (nbrs->a[how_many(&nbrs->a_state[0]) - 1] > nbrs->b[0]
				|| !nbrs->b_state[0]))
		{
			rra(nbrs, 0);
			j++;
		}
		else
			pa(nbrs, 0);
		i++;
	}
}
