/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:30:46 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 12:26:36 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_nbrs *nbrs, int a)
{
	int	temp;

	if (nbrs->a_state[0] && nbrs->a_state[1])
	{
		temp = nbrs->a[0];
		nbrs->a[0] = nbrs->a[1];
		nbrs->a[1] = temp;
		if (a == 0)
			ft_printf("sa\n");
	}
}

void	sb(t_nbrs *nbrs, int a)
{
	int	temp;

	if (nbrs->b_state[0] && nbrs->b_state[1])
	{
		temp = nbrs->b[0];
		nbrs->b[0] = nbrs->b[1];
		nbrs->b[1] = temp;
		if (a == 0)
			ft_printf("sb\n");
	}
}

void	ss(t_nbrs *nbrs, int a)
{
	sa(nbrs, 1);
	sb(nbrs, 1);
	if (a == 0)
		ft_printf("ss\n");
}

void	pa(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	if (!nbrs->b_state[0])
		return ;
	while (nbrs->a_state[i])
	{
		nbrs->temp[i + 1] = nbrs->a[i];
		i++;
	}
	nbrs->a_state[i] = 1;
	nbrs->temp[0] = nbrs->b[0];
	i = 0;
	while (nbrs->a_state[i])
	{
		nbrs->a[i] = nbrs->temp[i];
		i++;
	}
	delete_one(&nbrs->b[0], &nbrs->b_state[0], nbrs);
	if (a == 0)
		ft_printf("pa\n");
}

void	pb(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	if (!nbrs->a_state[0])
		return ;
	while (nbrs->b_state[i])
	{
		nbrs->temp[i + 1] = nbrs->b[i];
		i++;
	}
	nbrs->b_state[i] = 1;
	nbrs->temp[0] = nbrs->a[0];
	i = 0;
	while (nbrs->b_state[i])
	{
		nbrs->b[i] = nbrs->temp[i];
		i++;
	}
	delete_one(&nbrs->a[0], &nbrs->a_state[0], nbrs);
	if (a == 0)
		ft_printf("pb\n");
}
