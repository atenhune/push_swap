/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/16 00:44:41 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

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
		nbrs.a[i + nbrs.i] = ft_atoi(argv[i + 1]);
		nbrs.a_state[i + nbrs.i] = 1;
		if (lenght(nbrs.a[i + nbrs.i]) != ft_strlen(argv[i + 1]))
			intake(&nbrs, i, argv[i + 1]);
		i++;
	}
	if (check(&nbrs, 1))
		return (0);
	// split_big_small(&nbrs);
	// split(&nbrs);
	// sort_a(&nbrs);
	// testi_a(&nbrs);
	// testi_aaa(&nbrs);
	// sort_b(&nbrs);
	// testi_b(&nbrs);
	// merge(&nbrs);
	// smallest(&nbrs, &nbrs.a[0], &nbrs.a_state[0]);
	// reset(&nbrs);
	// no_sort_b(&nbrs);
	// four_smallest(&nbrs, 500);
	dup_check(&nbrs);

	// split_four(&nbrs, 23);

	// split_four_b(&nbrs, 25);						// 500numeroo -> 44
	// testi_b(&nbrs);								// 100numeroo -> 10
	// split_four(&nbrs, 14);
	// split_test(&nbrs, 25);
	// split_test_b(&nbrs, 8);
	// split_test(&nbrs, 50);
	// split_test_b(&nbrs, 25);
	// testi_aaa(&nbrs);
	// testi_aa(&nbrs);
	// split_test_b(&nbrs, 33);


	// half_split(&nbrs, 100);
	// half_split(&nbrs, 80);
	// half_split(&nbrs, 64);
	// half_split(&nbrs, 51);
	// half_split(&nbrs, 40);
	// half_split(&nbrs, 32);
	// half_split(&nbrs, 26);
	// half_split(&nbrs, 20);
	// half_split(&nbrs, 17);
	// half_split(&nbrs, 15);
	// half_split(&nbrs, 15);
	// half_split(&nbrs, 15);
	// half_split(&nbrs, 15);
	// half_split(&nbrs, 9);

	// half_split(&nbrs, 150);
	// half_split(&nbrs, 10);
	// half_split(&nbrs, 10);
	// half_split(&nbrs, 10);
	// half_split(&nbrs, 10);


	// half_split(&nbrs, 250);

	// split_test(&nbrs, 250);
	// split_test_b(&nbrs, 125);
	
	// split_test(&nbrs, 44);

	// printf("%.300f\n", 2.1231231231f);
    // ft_printf("%.300f\n", 2.1231231231f);
	// printf("|%.25f|\n", 1.15);
	// printf("|%.22f|\n", 1.15f);
    // ft_printf("|%.22f|\n", 1.15f);

	// sort_of_insertion(&nbrs, 3);

	// insertion_sort(&nbrs, 2);

	antti_sort(&nbrs);


	// no_sort_four(&nbrs);
	// no_sort_b(&nbrs);
	// ft_printf("%d %d %d %d\n", nbrs.fs[0], nbrs.fs[1], nbrs.fs[2], nbrs.fs[3]);
	// solution_printer(&nbrs);
	// printteri(&nbrs, 500);
	// ft_printf("%s\n\n OPERATIONS : %d\n\n", PURPLE, nbrs.operations);
	// ft_printf("\n\n OPERATIONS : %d\n\n", nbrs.operations);

}


