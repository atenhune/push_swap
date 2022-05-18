/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:39:02 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 18:55:02 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_a(t_nbrs *nbrs, int i, int a)
{
	if (a == 1 || a == 10)
		ft_printf("%s%d", GREEN, nbrs->a[i]);
	else if (a == 2 || a == 11)
		ft_printf("%s%d", RED, nbrs->a[i]);
	else if (a == 3 && i < 1)
		ft_printf("%s%d", BLUE, nbrs->a[i]);
	else if ((a == 4 || a == 9) && i < 2)
		ft_printf("%s%d", YELLOW, nbrs->a[i]);
	else
		ft_printf("%s%d", WHITE, nbrs->a[i]);
}

static void	print_b(t_nbrs *nbrs, int i, int a)
{
	if (a == 5 || a == 10)
		ft_printf("%s%d", GREEN, nbrs->b[i]);
	else if (a == 6 || a == 11)
		ft_printf("%s%d", RED, nbrs->b[i]);
	else if (a == 7 && i < 1)
		ft_printf("%s%d", BLUE, nbrs->b[i]);
	else if ((a == 8 || a == 9) && i < 2)
		ft_printf("%s%d", YELLOW, nbrs->b[i]);
	else
		ft_printf("%s%d", WHITE, nbrs->b[i]);
}

void	printter(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	if (nbrs->v == 0 && nbrs->c == 0)
		return ;
	if (nbrs->c == 0)
		a = 0;
	ft_printf("\n");
	ft_printf("%sStacks:\n", YELLOW);
	while ((nbrs->a_state[i] || nbrs->b_state[i]))
	{
		ft_printf("%s\t", WHITE);
		if (nbrs->a_state[i])
			print_a(nbrs, i, a);
		ft_printf("\t");
		if (nbrs->b_state[i])
			print_b(nbrs, i, a);
		ft_printf("\n");
		i++;
	}
	ft_printf("%s\n\t^\t^\n\tA\tB\n", WHITE);
}
