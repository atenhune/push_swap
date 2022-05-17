/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:46:36 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 17:48:51 by atenhune         ###   ########.fr       */
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

void	large_sort(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	pb(nbrs, 0);
	pb(nbrs, 0);
	while (nbrs->a_state[0])
	{
		actual_positions(nbrs, 0, 0, 0);
		select_nbr(nbrs);
		apply_moves(nbrs);
		pb(nbrs, 0);
	}
	reset_to_big(nbrs);
	while (i < nbrs->total_nbrs)
	{
		pa(nbrs, 0);
		i++;
	}
}
