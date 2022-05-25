/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_collector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:23:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/25 10:25:15 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	number_collector(t_nbrs *nbrs, int argc, char **argv)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = v_flag(nbrs, argv[1]);
	while (i < argc - j)
	{
		if ((i + nbrs->i) > 998)
			error_exit(nbrs, 0);
		nbrs->a[i + nbrs->i] = no_overflow_atoi(argv[i + j], nbrs);
		nbrs->a_state[i + nbrs->i] = 1;
		if ((argv[i + 1][0] < 48 || argv[i + 1][0] > 57)
			&& argv[i + 1][0] != '-')
			error_exit(nbrs, 0);
		temp = ft_strlen(argv[i + j]);
		if (lenght(nbrs->a[i + nbrs->i]) != temp)
			intake(nbrs, i, argv[i + j]);
		i++;
	}
}
