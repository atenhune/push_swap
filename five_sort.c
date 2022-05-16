/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:19:11 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/16 17:46:07 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"


static void	five_helper1(t_nbrs *nbrs)
{
	if (nbrs->b[0] > nbrs->biggest)
	{
		pa(nbrs, 0);
		rra(nbrs, 0);
		rra(nbrs, 0);
	}
	else if (nbrs->b[0] < nbrs->smallest)
	{
		ra(nbrs, 0);
		pa(nbrs, 0);
	}
	else
	{
		if (nbrs->b[0] > nbrs->a[2])
		{
			rra(nbrs, 0);
			pa(nbrs, 0);
			rra(nbrs, 0);
			rra(nbrs, 0);
			return ;
		}
		ra(nbrs, 0);
		pa(nbrs, 0);
		sa(nbrs, 0);
	}
}

static void	five_helper2(t_nbrs *nbrs)
{
	if (nbrs->b[0] > nbrs->biggest)
	{
		pa(nbrs, 0);
		ra(nbrs, 0);
		pa(nbrs, 0);
		ra(nbrs, 0);
	}
	else if (nbrs->b[0] < nbrs->smallest)
	{
		pa(nbrs, 0);
		pa(nbrs, 0);
		ra(nbrs, 0);
	}
}

static void	five_helper3(t_nbrs *nbrs)
{
	if (nbrs->b[0] < nbrs->a[1])
	{
		pa(nbrs, 0);
		sa(nbrs, 0);
		pa(nbrs, 0);
		ra(nbrs, 0);
	}
	else if (nbrs->b[0] < nbrs->a[2])
	{
		sb(nbrs, 0);
		pa(nbrs, 0);
		rra(nbrs, 0);
		pa(nbrs, 0);
		rra(nbrs, 0);
		rra(nbrs, 0);
	}
}

static void	five_helper0(t_nbrs *nbrs)
{
	if (nbrs->b[0] > nbrs->biggest && nbrs->b[0] > nbrs->b[1])
	{
		pa(nbrs, 0);
		five_helper1(nbrs);
	}
	else
	{
		five_helper2(nbrs);
		five_helper3(nbrs);
	}
}

void	five_sort(t_nbrs *nbrs)
{
	pb(nbrs, 0);
	pb(nbrs, 0);
	if (!check(nbrs, 1))
		three_sort(nbrs);
	biggest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	if (nbrs->b[0] > nbrs->biggest || nbrs->b[1] > nbrs->biggest)
		five_helper0(nbrs);
	else
	{
		if (nbrs->b[0] > nbrs->b[1])
			sb(nbrs, 0);
		while (nbrs->b_state[0])
		{
			while (nbrs->a[0] < nbrs->b[0])
				ra(nbrs, 0);
			pa(nbrs, 0);
		}
		reset_to_smallest(nbrs);
	}
}
