/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:12:09 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 17:45:29 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_moves(t_nbrs *nbrs)
{
	int	i;
	int	temp;

	i = 0;
	while (i < nbrs->a_c)
	{
		temp = nbrs->mv[i][0];
		if (nbrs->mv[i][1] > nbrs->mv[i][0])
			temp = nbrs->mv[i][1];
		if (nbrs->mv[i][2] != nbrs->mv[i][3])
			nbrs->mv[i][4] = nbrs->mv[i][0] + nbrs->mv[i][1];
		else
			nbrs->mv[i][4] = temp;
		i++;
	}
}

static void	direction_help(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	while (i < nbrs->a_c)
	{
		nbrs->mv[i][0] = i;
		if (i > nbrs->a_c / 2)
		{
			nbrs->mv[i][0] = nbrs->a_c - i;
			nbrs->mv[i][2] = 1;
		}
		if (nbrs->mv[i][1] > nbrs->b_c / 2)
		{
			nbrs->mv[i][1] = nbrs->b_c - nbrs->mv[i][1];
			nbrs->mv[i][3] = 1;
		}
		i++;
	}
	set_moves(nbrs);
}

static void	direction(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	nbrs->a_c = how_many(&nbrs->a_state[0]);
	nbrs->b_c = how_many(&nbrs->b_state[0]);
	while (i < nbrs->total_nbrs)
	{
		nbrs->mv[i][2] = 0;
		nbrs->mv[i][3] = 0;
		i++;
	}
	direction_help(nbrs);
}

static void	position_help(t_nbrs *nbrs, int i, int j, int k)
{
	while (nbrs->a[i] < nbrs->b[nbrs->position + j]
		&& nbrs->b_state[nbrs->position + j])
		j++;
	if (!nbrs->b_state[nbrs->position + j])
	{
		j = 0;
		k = 1;
		while (nbrs->a[i] < nbrs->b[j] && j < nbrs->position)
			j++;
	}
	if (k != 1)
		nbrs->mv[i][1] = nbrs->position + j;
	else
		nbrs->mv[i][1] = j;
}

void	actual_positions(t_nbrs *nbrs, int i, int j, int k)
{
	biggest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
	while (nbrs->a_state[i])
	{
		if (nbrs->a[i] > nbrs->biggest)
			nbrs->mv[i][1] = nbrs->position;
		else
			position_help(nbrs, i, j, k);
		i++;
		j = 0;
	}
	direction(nbrs);
}
