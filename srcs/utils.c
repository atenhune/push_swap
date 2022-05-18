/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:35:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 16:44:29 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_one(int *arr, int *arr_state, t_nbrs *nbrs)
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

t_nbrs	initialize(int i)
{
	t_nbrs	nbrs;

	while (i < 1000)
	{
		nbrs.a[i] = 0;
		nbrs.b[i] = 0;
		nbrs.a_state[i] = 0;
		nbrs.b_state[i] = 0;
		nbrs.temp[i] = 0;
		nbrs.temp_state[i] = 0;
		nbrs.mv[i][0] = 0;
		nbrs.mv[i][1] = 0;
		nbrs.mv[i][2] = 0;
		nbrs.mv[i][3] = 0;
		nbrs.mv[i++][4] = 0;
	}
	nbrs.total_nbrs = 0;
	nbrs.smallest = 0;
	nbrs.biggest = 0;
	nbrs.position = 0;
	nbrs.i = 0;
	nbrs.a_c = 0;
	nbrs.b_c = 0;
	nbrs.v = 0;
	nbrs.c = 0;
	return (nbrs);
}

static void	do_check(t_nbrs *nbrs, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbrs->a_state[i])
	{
		while (nbrs->temp_state[j])
		{
			if (j == i)
				j++;
			if (nbrs->a[i] == nbrs->temp[j] && j < count)
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	dup_check(t_nbrs *nbrs)
{
	int	count;
	int	i;

	i = 0;
	count = how_many(&nbrs->a_state[0]);
	nbrs->total_nbrs = count;
	while (nbrs->a_state[i])
	{
		nbrs->temp[i] = nbrs->a[i];
		nbrs->temp_state[i] = 1;
		i++;
	}
	do_check(nbrs, count);
}
