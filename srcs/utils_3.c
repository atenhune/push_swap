/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:00:18 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/18 19:43:58 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_nbrs *nbrs, int a)
{
	if (a == 1)
	{
		ft_memdel((void *)&nbrs->str);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

int	strlen_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

int	check(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	while (nbrs->a_state[i])
	{
		if (nbrs->a[i] > nbrs->a[i + 1] && nbrs->a_state[i + 1])
		{
			if (a == 0)
				ft_printf("KO\n");
			return (0);
		}
		i++;
	}
	if (a == 0)
		ft_printf("OK\n");
	return (1);
}

void	intake(t_nbrs *nbrs, int i, char *av)
{
	int	j;
	int	limit;

	j = 0;
	limit = ft_strlen(av);
	while (j < limit)
	{
		if (i > 998)
			error_exit(nbrs, 0);
		nbrs->a[i] = no_overflow_atoi(&av[j], nbrs);
		nbrs->a_state[i] = 1;
		if (lenght(nbrs->a[i]) != strlen_whitespace(&av[j]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		j = lenght(nbrs->a[i]) + j + 1;
		nbrs->i++;
		i++;
	}
}

int	lenght(int nbr)
{
	int	ret;

	ret = 0;
	if (nbr <= 0)
		ret++;
	while (nbr != 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}
