/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:37 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 19:30:20 by atenhune         ###   ########.fr       */
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

static int	v_flag(t_nbrs *nbrs, char *av)
{
	nbrs->v = 0;
	nbrs->c = 0;
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

static void	number_collector(t_nbrs *nbrs, int argc, char **argv)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = v_flag(nbrs, argv[1]);
	while (i < argc - j)
	{
		if ((i + nbrs->i) > 999)
			error_exit(nbrs, 0);
		nbrs->a[i + nbrs->i] = no_overflow_atoi(argv[i + j], nbrs);
		nbrs->a_state[i + nbrs->i] = 1;
		temp = ft_strlen(argv[i + j]);
		if (lenght(nbrs->a[i + nbrs->i]) != temp)
			intake(nbrs, i, argv[i + j]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_nbrs	nbrs;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	nbrs = initialize(0);
	number_collector(&nbrs, argc, argv);
	dup_check(&nbrs);
	if (check(&nbrs, 1))
		return (0);
	choose_algo(&nbrs);
	// printter(&nbrs, 0);
}
