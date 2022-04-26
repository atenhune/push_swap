/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/26 14:23:56 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

t_nbrs	initialize(int argc)
{
	t_nbrs	nbrs;
	int i;

	i = 0;
	while (i <= argc)
	{
		nbrs.a[i] = 0;
		nbrs.b[i] = 0;
		nbrs.a_state[i] = 0;
		nbrs.b_state[i] = 0;
		nbrs.temp[i] = 0;
		i++;
	}
	return (nbrs);
}

int main(int argc, char **argv)
{
	t_nbrs nbrs;
	int	i;

	i = 0;
	if (argc < 2)
		exit(0);
	nbrs = initialize(argc);
	while (i < argc - 1)
	{
		nbrs.a[i] = ft_atoi(argv[i + 1]);
		nbrs.a_state[i] = 1;
		i++;
	}
	i = 0;
	// sa(&nbrs);
	pb(&nbrs);
	pb(&nbrs);
	rrr(&nbrs);
	while (i < argc)
	{
		if (nbrs.a_state[i])
			ft_printf("%d", nbrs.a[i]);
		ft_printf("\t");
		if (nbrs.b_state[i])
			ft_printf("%d", nbrs.b[i]);
		ft_printf("\n");
		i++;
	}
}