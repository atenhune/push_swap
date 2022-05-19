/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:53:49 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 14:07:04 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_to_big(t_nbrs *nbrs)
{
	int	limit;

	limit = how_many(&nbrs->b_state[0]) / 2;
	biggest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
	while (nbrs->b[0] != nbrs->biggest)
	{
		if (nbrs->position <= limit)
			rb(nbrs, 0);
		else
			rrb(nbrs, 0);
	}
}

void	reset_to_smallest(t_nbrs *nbrs)
{
	int	limit;

	if (!nbrs->a_state[0])
		return ;
	limit = how_many(&nbrs->a_state[0]) / 2;
	smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	while (nbrs->a[0] != nbrs->smallest)
	{
		if (nbrs->position <= limit)
			ra(nbrs, 0);
		else
			rra(nbrs, 0);
	}
}

void	smallest(t_nbrs *nbrs, int *arr, int *arr_state)
{
	int	smallest;
	int	i;
	int	count;

	i = 0;
	count = how_many(&arr_state[0]);
	while (i < count)
	{
		if (i == 0)
		{
			smallest = arr[i];
			nbrs->position = i;
		}
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			nbrs->position = i;
		}
		i++;
	}
	nbrs->smallest = smallest;
}

void	biggest(t_nbrs *nbrs, int *arr, int *arr_state)
{
	int	biggest;
	int	i;
	int	count;

	i = 0;
	count = how_many(&arr_state[0]);
	while (i < count)
	{
		if (i == 0)
		{
			biggest = arr[i];
			nbrs->position = i;
		}
		if (arr[i] > biggest)
		{
			biggest = arr[i];
			nbrs->position = i;
		}
		i++;
	}
	nbrs->biggest = biggest;
}
