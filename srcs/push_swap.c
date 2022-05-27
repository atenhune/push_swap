/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/27 15:05:58 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_algo(t_nbrs *nbrs)
{
	if (nbrs->total_nbrs == 2)
		sa(nbrs, 0);
	else if (nbrs->total_nbrs == 3)
		three_sort(nbrs);
	else if (nbrs->total_nbrs == 4)
		four_sort(nbrs);
	else if (nbrs->total_nbrs == 5)
		five_sort(nbrs);
	else
		large_sort(nbrs, 0, 0);
}

int	main(int argc, char **argv)
{
	t_nbrs	nbrs;

	if (argc < 2)
		return (0);
	nbrs = initialize(0);
	number_collector(&nbrs, argc, argv);
	dup_check(&nbrs);
	if (check(&nbrs, 1))
		return (0);
	choose_algo(&nbrs);
}
