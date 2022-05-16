/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 01:09:34 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_algo(t_nbrs *nbrs)
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
		large_sort(nbrs);
}

int main(int argc, char **argv)
{
	t_nbrs nbrs;
	int	i;

	i = 0;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	nbrs = initialize(argc);
	while (i < argc - 1)
	{
		nbrs.a[i + nbrs.i] = no_overflow_atoi(argv[i + 1], &nbrs);
		nbrs.a_state[i + nbrs.i] = 1;
		if (lenght(nbrs.a[i + nbrs.i]) != ft_strlen(argv[i + 1]))
			intake(&nbrs, i, argv[i + 1]);
		i++;
	}
	dup_check(&nbrs);
	if (check(&nbrs, 1))
		return (0);
	choose_algo(&nbrs);
	// pb(&nbrs, 0);
	// pb(&nbrs, 0);
	// three_sort(&nbrs);
	// pa(&nbrs, 0);
	// ra(&nbrs, 0);
	// pa(&nbrs, 0);
	// ra(&nbrs, 0);
	// pb(&nbrs, 0);
	// ra(&nbrs, 0);
	// pa(&nbrs, 0);
	// pa(&nbrs, 0);
	// rra(&nbrs, 0);
	// rra(&nbrs, 0);
	// rra(&nbrs, 0);


	// no_sort_four(&nbrs);
	// no_sort_b(&nbrs);
	// ft_printf("%d %d %d %d\n", nbrs.fs[0], nbrs.fs[1], nbrs.fs[2], nbrs.fs[3]);
	// solution_printer(&nbrs);
	// printteri(&nbrs, 500);
	// ft_printf("%s\n\n OPERATIONS : %d\n\n", PURPLE, nbrs.operations);
	// ft_printf("\n\n OPERATIONS : %d\n\n", nbrs.operations);

}


