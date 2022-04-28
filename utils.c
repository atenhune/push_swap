/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:35:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/28 14:31:39 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

void	delete(int *arr, int *arr_state, t_nbrs *nbrs)
{
	int	i;

	i = 0;
	while (arr_state[i])
	{
		nbrs->temp[i] = arr[i + 1];
		i++;
	}
	arr_state[i - 1] = 0;
	i = 0;
	while (arr_state[i])
	{
		arr[i] = nbrs->temp[i];
		i++;
	}
}

int	how_many(int *arr_state)
{
	int	i;

	i = 0;
	while (arr_state[i])
		i++;
	return (i);
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

void	biggest(t_nbrs *nbrs)
{
	int	biggest;
	int	i;
	int	count;

	i = 0;
	count = how_many(&nbrs->a_state[0]);
	while (i < count)
	{
		if (i == 0)
		{
			biggest = nbrs->a[i];
			nbrs->position = i;
		}
		if (nbrs->a[i] > biggest)
		{
			biggest = nbrs->a[i];
			nbrs->position = i;
		}
		i++;
	}
	nbrs->biggest = biggest;
}