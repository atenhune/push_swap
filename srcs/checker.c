/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:08:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/17 00:46:21 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_space(t_nbrs *nbrs, char *str, int *space)
{
	char	*temp;

	temp = better_ft_strnew(*space);
	ft_strcat(temp, str);
	ft_memdel((void *)&str);
	*space *= 2;
	nbrs->str = better_ft_strnew(*space);
	ft_strcat(nbrs->str, temp);
	ft_memdel((void *)&temp);
}

static void	get_operations(t_nbrs *nbrs)
{
	int		read_ret;
	int		space;
	int		ret;
	char	buf[2];

	read_ret = 1;
	space = 5000;
	ret = 0;
	nbrs->str = better_ft_strnew(space);
	while (read_ret > 0)
	{
		read_ret = read(0, &buf, 1);
		ret += read_ret;
		buf[1] = '\0';
		if (read_ret != 0)
		{
			if (ret == space - 10)
				double_space(nbrs, nbrs->str, &space);
			ft_strcat(nbrs->str, buf);
		}
		if (read_ret == -1)
			error_exit(nbrs, 1);
	}
}

static void	apply_helper(int i, t_nbrs *nbrs)
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
		error_exit(nbrs, 1);
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
		{
			if (nbrs->str[i + j] != 'a' && nbrs->str[i + j] != 'b'
				&& nbrs->str[i + j] != 'p' && nbrs->str[i + j] != 'r'
				&& nbrs->str[i + j] != 's')
				error_exit(nbrs, 1);
			j++;
		}
		apply_helper(i, nbrs);
		nbrs->operations++;
		i = i + j + 1;
		j = 0;
	}
	ft_memdel((void *)&nbrs->str);
}

int	main(int argc, char **argv)
{
	t_nbrs	nbrs;
	int		i;

	i = 0;
	nbrs = initialize(argc);
	if (argc == 1)
		return (0);
	while (i < argc - 1)
	{
		nbrs.a[i + nbrs.i] = no_overflow_atoi(argv[i + 1], &nbrs);
		nbrs.a_state[i + nbrs.i] = 1;
		if (lenght(nbrs.a[i + nbrs.i]) != ft_strlen(argv[i + 1]))
			intake(&nbrs, i, argv[i + 1]);
		i++;
	}
	dup_check(&nbrs);
	get_operations(&nbrs);
	apply_operations(&nbrs);
	check(&nbrs, 0);
	// printf("\n\nOPERATIONS : %d\n\n", nbrs.operations);
}
