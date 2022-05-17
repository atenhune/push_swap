/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:49:20 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 17:09:05 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_helper1(t_nbrs *nbrs, int temp, int temp2)
{
	int	i;

	i = 0;
	while (i < temp && nbrs->mv[nbrs->selected][0] != 0 && nbrs->mv[nbrs->selected][1] != 0)
	{
		rr(nbrs, 0);
		i++;
	}
	if (nbrs->mv[nbrs->selected][0] == temp2)
	{
		while (i < temp2)
		{
			ra(nbrs, 0);
			i++;
		}
	}
	else
	{
		while (i < temp2)
		{
			rb(nbrs, 0);
			i++;
		}
	}
}

static void	apply_helper2(t_nbrs *nbrs, int temp, int temp2)
{
	int	i;

	i = 0;
	while (i < temp && nbrs->mv[nbrs->selected][0] != 0 && nbrs->mv[nbrs->selected][1] != 0)
	{
		rrr(nbrs, 0);
		i++;
	}
	if (nbrs->mv[nbrs->selected][0] == temp2)
	{
		while (i < temp2)
		{
			rra(nbrs, 0);
			i++;
		}
	}
	else
	{
		while (i < temp2)
		{
			rrb(nbrs, 0);
			i++;
		}
	}
}

static void apply_helper3(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	if (nbrs->mv[nbrs->selected][2] == 0)
	{
		while (i < nbrs->mv[nbrs->selected][0])
		{
			ra(nbrs, 0);
			i++;
		}
	}
	if (nbrs->mv[nbrs->selected][2] == 1)
	{
		while (i < nbrs->mv[nbrs->selected][0])
		{
			rra(nbrs, 0);
			i++;
		}
	}
}

static void	apply_helper4(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	if (nbrs->mv[nbrs->selected][3] == 0)
	{
		while (i < nbrs->mv[nbrs->selected][1])
		{
			rb(nbrs, 0);
			i++;
		}
	}
	if (nbrs->mv[nbrs->selected][3] == 1)
	{
		while (i < nbrs->mv[nbrs->selected][1])
		{
			rrb(nbrs, 0);
			i++;
		}
	}
}

void	apply_moves(t_nbrs *nbrs)
{
	int	temp;
	int	temp2;

	temp = nbrs->mv[nbrs->selected][0];
	temp2 = nbrs->mv[nbrs->selected][1];
	if (nbrs->mv[nbrs->selected][1] < nbrs->mv[nbrs->selected][0])
	{
		temp = nbrs->mv[nbrs->selected][1];
		temp2 = nbrs->mv[nbrs->selected][0];
	}
	if (nbrs->mv[nbrs->selected][2] == nbrs->mv[nbrs->selected][3])
	{
		if (nbrs->mv[nbrs->selected][2] == 0)
			apply_helper1(nbrs, temp, temp2);
		else
			apply_helper2(nbrs, temp, temp2);
	}
	else
	{
		apply_helper3(nbrs);
		apply_helper4(nbrs);
	}
}