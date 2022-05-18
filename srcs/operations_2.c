/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:30:23 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 17:28:08 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_nbrs *nbrs, int a)
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
	if (a == 0)
	{
		ft_printf("ra\n");
		// printter(nbrs, 1);
	}
}

void	rb(t_nbrs *nbrs, int a)
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
	if (a == 0)
	{
		ft_printf("rb\n");
		// printter(nbrs, 5);
	}
}

void	rr(t_nbrs *nbrs, int a)
{
	ra(nbrs, 1);
	rb(nbrs, 1);
	if (a == 0)
	{
		ft_printf("rr\n");
		// printter(nbrs, 10);
	}
}

void	rra(t_nbrs *nbrs, int a)
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
	if (a == 0)
	{
		ft_printf("rra\n");
		// printter(nbrs, 2);
	}
}

void	rrb(t_nbrs *nbrs, int a)
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
	if (a == 0)
	{
		ft_printf("rrb\n");
		// printter(nbrs, 6);
	}
}
