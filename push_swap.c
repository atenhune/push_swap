/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/09 17:30:40 by atenhune         ###   ########.fr       */
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
	i = 0;
	// split_big_small(&nbrs);
	// split(&nbrs);
	// sort_a(&nbrs);
	// testi_a(&nbrs);
	// testi_aa(&nbrs);
	// testi_aaa(&nbrs);
	// sort_b(&nbrs);
	// testi_b(&nbrs);
	// merge(&nbrs);
	// smallest(&nbrs, &nbrs.a[0], &nbrs.a_state[0]);
	// reset(&nbrs);
	// no_sort_b(&nbrs);
	// four_smallest(&nbrs);
	split_four(&nbrs);
	no_sort_four(&nbrs);
	// ft_printf("%d %d %d %d\n", nbrs.fs[0], nbrs.fs[1], nbrs.fs[2], nbrs.fs[3]);
	// printteri(&nbrs);
	// ft_printf("\n\n OPERATIONS : %d\n\n", nbrs.operations);
}