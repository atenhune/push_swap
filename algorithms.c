/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:37:30 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/03 15:15:34 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

void	split(t_nbrs *nbrs)
{
	int count;

	count = how_many(&nbrs->a_state[0]);
	count /= 2;
	while (count > 0)
	{
		pb(nbrs, 0);
		count--;
		nbrs->operations++;
	}
}

void	sort_a(t_nbrs *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs->a_state[i])
	{
		if (nbrs->a[i] > nbrs->a[i + 1] && nbrs->a_state[i] && nbrs->a_state[i + 1])
		{
			if (i != 0)
			{
				j = 0;
				while (j < i)
				{
					ra(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				sa(nbrs, 0);
				nbrs->operations++;
				j = 0;
				while (j < i)
				{
					rra(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				i = -1;
			}
			else
			{
				sa(nbrs, 0);
				nbrs->operations++;
				i = -1;
			}
		}
		i++;
	}
}

void	sort_b(t_nbrs *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs->b_state[i])
	{
		if (nbrs->b[i] > nbrs->b[i + 1] && nbrs->b_state[i] && nbrs->b_state[i + 1])
		{
			if (i != 0)
			{
				j = 0;
				while (j < i)
				{
					rb(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				sb(nbrs, 0);
				nbrs->operations++;
				j = 0;
				while (j < i)
				{
					rrb(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				i = -1;
			}
			else
			{
				sb(nbrs, 0);
				nbrs->operations++;
				i = -1;
			}
		}
		i++;
	}
}

void	merge(t_nbrs *nbrs)
{
	int	count;
	int	i;

	count = how_many(&nbrs->a_state[0]);
	i = 0;
	while (nbrs->b_state[0])
	{
		if (nbrs->a[0] > nbrs->b[0])
		{
			pa(nbrs, 0);
			nbrs->operations++;
			ra(nbrs, 0);
			nbrs->operations++;
		}
		else
		{
			if (i == count)
			{
				pa(nbrs, 0);
				nbrs->operations++;
				ra(nbrs, 0);
				nbrs->operations++;
			}
			else
			{
				ra(nbrs, 0);
				nbrs->operations++;
				i++;
			}
		}
	}
}

void	reset(t_nbrs *nbrs)
{
	while (nbrs->a[0] != nbrs->smallest)
	{
		ra(nbrs, 0);
		nbrs->operations++;
	}
}

void	testi_a(t_nbrs *nbrs)
{
	int	limit;
	int	count;

	count = how_many(&nbrs->a_state[0]);
	while (nbrs->a_state[0])
	{
		smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
		limit = how_many(&nbrs->a_state[0]) / 2;
		while (nbrs->a[0] != nbrs->smallest)
		{
			if (nbrs->position <= limit)
				ra(nbrs, 0);
			else
				rra(nbrs, 0);
			nbrs->operations++;
		}
		pb(nbrs, 0);
		nbrs->operations++;
	}
	while (count > 0)
	{
		pa(nbrs, 0);
		nbrs->operations++;
		count--;
	}
}

void	testi_b(t_nbrs *nbrs)
{
	int	limit;
	int	count;

	count = how_many(&nbrs->b_state[0]);
	while (nbrs->b_state[0])
	{
		smallest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
		limit = how_many(&nbrs->b_state[0]) / 2;
		while (nbrs->b[0] != nbrs->smallest)
		{
			if (nbrs->position <= limit)
				rb(nbrs, 0);
			else
				rrb(nbrs, 0);
			nbrs->operations++;
		}
		pa(nbrs, 0);
		nbrs->operations++;
	}
	while (count > 0)
	{
		pb(nbrs, 0);
		nbrs->operations++;
		count--;
	}
}