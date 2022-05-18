/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 17:01:47 by atenhune         ###   ########.fr       */
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
		large_sort(nbrs, 0, 0);
}

static int	v_flag(t_nbrs *nbrs, char *av)
{
	if (ft_strcmp("-v", av) == 0)
	{
		nbrs->v = 1;
		return (2);
	}
	if (ft_strcmp("-c", av) == 0)
	{
		nbrs->c = 1;
		return (2);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_nbrs	nbrs;
	int		i;
	int		j;
	int		temp;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	nbrs = initialize(0);
	i = 0;
	j = v_flag(&nbrs, argv[1]);
	while (i < argc - j)
	{
		nbrs.a[i + nbrs.i] = no_overflow_atoi(argv[i + j], &nbrs);
		nbrs.a_state[i + nbrs.i] = 1;
		temp = ft_strlen(argv[i + j]);
		if (lenght(nbrs.a[i + nbrs.i]) != temp)
			intake(&nbrs, i, argv[i + j]);
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
	// printer(&nbrs);
	// ft_printf("%s\n\n OPERATIONS : %d\n\n", PURPLE, nbrs.operations);
	// ft_printf("\n\n OPERATIONS : %d\n\n", nbrs.operations);

}

