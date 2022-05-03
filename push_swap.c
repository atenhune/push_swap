/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/03 13:24:05 by atenhune         ###   ########.fr       */
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
		nbrs.a[i] = ft_atoi(argv[i + 1]);
		nbrs.a_state[i] = 1;
		i++;
	}
	i = 0;
	split(&nbrs);
	// sort_a(&nbrs);
	testi_a(&nbrs);
	// sort_b(&nbrs);
	testi_b(&nbrs);
	merge(&nbrs);
	smallest(&nbrs, &nbrs.a[0], &nbrs.a_state[0]);
	reset(&nbrs);
	// while (i < argc)
	// {
	// 	if (nbrs.a_state[i])
	// 		ft_printf("%d", nbrs.a[i]);
	// 	ft_printf("\t");
	// 	if (nbrs.b_state[i])
	// 		ft_printf("%d", nbrs.b[i]);
	// 	ft_printf("\n");
	// 	i++;
	// }
	// ft_printf("\n\n OPERATIONS : %d\n\n", nbrs.operations);
}