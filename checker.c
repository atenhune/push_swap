/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:08:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/16 00:51:54 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

static int	space(void)
{
	int	read_ret;
	int	ret;
	char buf[2];

	read_ret = 1;
	ret = 0;
	while(read_ret > 0)
	{
		read_ret = read(0, &buf, 1);
		buf[1] = '\0';
		if (read_ret != 0)
			ret += read_ret;
		if (read_ret == -1)
			exit(0);
	}
	return (ret);
}

static void	get_operations(t_nbrs *nbrs, int argc)
{
	int	read_ret;
	char buf[2];

	read_ret = 1;
	// printf("%d", space());
	// exit(0);
	nbrs->str = better_ft_strnew(10000);
	// printf("%s\n", nbrs->str);
	while(read_ret > 0)
	{
		read_ret = read(0, &buf, 1);
		buf[1] = '\0';
		if (read_ret != 0)
			ft_strcat(nbrs->str, buf);
		// printf("%zu [%d]\n", ft_strlen(nbrs->str), read_ret);
		// exit(0);
		if (read_ret == -1)
			exit(0);
	}
	// printf("%s\n", nbrs->str);
	// exit(0);
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
		// printf("%s", nbrs->str);
		ft_memdel((void *)&nbrs->str);
		ft_putstr_fd("Error\n", 2);
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
		nbrs->operations++;
		i = i + j + 1;
		j = 0;
	}
}


int	main(int argc, char **argv)
{
	t_nbrs nbrs;
	int	i;

	i = 0;
	nbrs = initialize(argc);
	while (i < argc - 1)
	{
		nbrs.a[i + nbrs.i] = ft_atoi(argv[i + 1]);
		nbrs.a_state[i + nbrs.i] = 1;
		if (lenght(nbrs.a[i + nbrs.i]) != ft_strlen(argv[i + 1]))
			intake(&nbrs, i, argv[i + 1]);
		i++;
	}
	dup_check(&nbrs);
	get_operations(&nbrs, argc);
	apply_operations(&nbrs);
	check(&nbrs, 0);
	printf("\n\nOPERATIONS : %d\n\n", nbrs.operations);

}