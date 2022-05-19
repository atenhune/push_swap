/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:50:20 by antti             #+#    #+#             */
/*   Updated: 2022/05/16 22:07:26 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_sort(t_nbrs *nbrs)
{
	pb(nbrs, 0);
	if (!check(nbrs, 1))
		three_sort(nbrs);
	smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	biggest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	if (nbrs->b[0] < nbrs->smallest)
		pa(nbrs, 0);
	else if (nbrs->b[0] > nbrs->biggest)
	{
		pa(nbrs, 0);
		ra(nbrs, 0);
	}
	else if (nbrs->b[0] > nbrs->a[0] && nbrs->b[0] < nbrs->a[1])
	{
		ra(nbrs, 0);
		pa(nbrs, 0);
		rra(nbrs, 0);
	}
	else
	{
		rra(nbrs, 0);
		pa(nbrs, 0);
		ra(nbrs, 0);
		ra(nbrs, 0);
	}
}
