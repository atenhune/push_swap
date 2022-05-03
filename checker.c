/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:08:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/03 15:16:41 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"
#include <stdio.h>

static void	get_operations(t_nbrs *nbrs, int argc)
{
	int	read_ret;
	char buf[4096];

	read_ret = read(0, &buf, 4096);
	if (read_ret == -1)
		exit(0);
	nbrs->str = better_ft_strnew(argc * 4);
	while(read_ret != 0)
	{
		// ft_strjoin(nbrs->str, buf);
		ft_strcat(nbrs->str, buf);
		read_ret = read(0, &buf, 4096);
		if (read_ret == -1)
			exit(0);
	}
	// printf("%s\n", nbrs->str);
}

static void apply_helper(int i, t_nbrs *nbrs)
{
	if (ft_strncmp(&nbrs->str[i], "pa", 2) == 0)
		pa(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "pb", 2) == 0)
		pb(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "sa", 2) == 0)
		sa(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "sb", 2) == 0)
		sb(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "ss", 2) == 0)
		ss(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "rra", 3) == 0)
		rra(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "rrb", 3) == 0)
		rrb(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "rrr", 3) == 0)
		rrr(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "ra", 2) == 0)
		ra(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "rb", 2) == 0)
		rb(nbrs, 1);
	else if (ft_strncmp(&nbrs->str[i], "rr", 2) == 0)
		rr(nbrs, 1);
	else
	{
		ft_printf("error\n");
		exit(0);
	}
}

static void	apply_operations(t_nbrs *nbrs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbrs->str[i] != '\0')
	{
		while (nbrs->str[i + j] != '\n')
			j++;
		apply_helper(i, nbrs);
		i = i + j + 1;
		j = 0;
	}
}

static void check(t_nbrs *nbrs)
{
	int	i;

	i = 0;
	while (nbrs->a_state[i])
	{
		if (nbrs->a[i] > nbrs->a[i + 1] && nbrs->a_state[i + 1])
		{
			ft_printf("KO\n");
			exit(0);
		}
		i++;
	}
	ft_printf("OK\n");
}


int	main(int argc, char **argv)
{
	t_nbrs nbrs;
	int	i;

	i = 0;
	nbrs = initialize(argc);
	while (i < argc - 1)
	{
		nbrs.a[i] = ft_atoi(argv[i + 1]);
		nbrs.a_state[i] = 1;
		i++;
	}
	// ft_putstr("moro\n");
	get_operations(&nbrs, argc);
	apply_operations(&nbrs);
	check(&nbrs);
	i = 0;
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