/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:42:04 by antti             #+#    #+#             */
/*   Updated: 2022/05/16 22:43:10 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_nbrs *nbrs)
{
	smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	if (nbrs->position == 0)
	{
		rra(nbrs, 0);
		sa(nbrs, 0);
	}
	else if (nbrs->position == 1)
	{
		biggest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
		if (nbrs->position == 2)
			sa(nbrs, 0);
		else
			ra(nbrs, 0);
	}
	else if (nbrs->position == 2)
	{
		biggest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
		if (nbrs->position == 1)
			rra(nbrs, 0);
		else
		{
			ra(nbrs, 0);
			sa(nbrs, 0);
		}
	}
}
