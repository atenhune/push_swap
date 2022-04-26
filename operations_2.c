/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:30:23 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/26 14:18:16 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

void	ra(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->a_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == 0)
			nbrs->temp[count - 1] = nbrs->a[i];
		else
			nbrs->temp[i - 1] = nbrs->a[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->a[i] = nbrs->temp[i];
		i++;
	}
}

void	rb(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->b_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == 0)
			nbrs->temp[count - 1] = nbrs->b[i];
		else
			nbrs->temp[i - 1] = nbrs->b[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->b[i] = nbrs->temp[i];
		i++;
	}
}

void	rr(t_nbrs *nbrs)
{
	ra(nbrs);
	rb(nbrs);
}

void	rra(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->a_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == count - 1)
			nbrs->temp[0] = nbrs->a[i];
		else
			nbrs->temp[i + 1] = nbrs->a[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->a[i] = nbrs->temp[i];
		i++;
	}
}

void	rrb(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->b_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == count - 1)
			nbrs->temp[0] = nbrs->b[i];
		else
			nbrs->temp[i + 1] = nbrs->b[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->b[i] = nbrs->temp[i];
		i++;
	}
}

void	rrr(t_nbrs *nbrs)
{
	rra(nbrs);
	rrb(nbrs);
}