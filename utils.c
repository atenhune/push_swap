/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:35:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/16 13:36:50 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

void	delete(int *arr, int *arr_state, t_nbrs *nbrs)
{
	int	i;

	i = 0;
	while (arr_state[i])
	{
		nbrs->temp2[i] = arr[i + 1];
		i++;
	}
	arr_state[i - 1] = 0;
	i = 0;
	while (arr_state[i])
	{
		arr[i] = nbrs->temp2[i];
		i++;
	}
}

int	how_many(int *arr_state)
{
	int	i;

	i = 0;
	while (arr_state[i])
		i++;
	return (i);
}

void	smallest(t_nbrs *nbrs, int *arr, int *arr_state)
{
	int	smallest;
	int	i;
	int	count;

	i = 0;
	count = how_many(&arr_state[0]);
	while (i < count)
	{
		if (i == 0)
		{
			smallest = arr[i];
			nbrs->position = i;
		}
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			nbrs->position = i;
		}
		i++;
	}
	nbrs->smallest = smallest;
}

void	biggest(t_nbrs *nbrs, int *arr, int *arr_state)
{
	int	biggest;
	int	i;
	int	count;

	i = 0;
	count = how_many(&arr_state[0]);
	while (i < count)
	{
		if (i == 0)
		{
			biggest = arr[i];
			nbrs->position = i;
		}
		if (arr[i] > biggest)
		{
			biggest = arr[i];
			nbrs->position = i;
		}
		i++;
	}
	nbrs->biggest = biggest;
}

t_nbrs	initialize(int argc)
{
	t_nbrs	nbrs;
	int i;

	i = 0;
	argc++;
	argc--;
	while (i < 1000)
	{
		nbrs.a[i] = 0;
		nbrs.b[i] = 0;
		nbrs.a_state[i] = 0;
		nbrs.b_state[i] = 0;
		nbrs.temp[i] = 0;
		nbrs.temp2[i] = 0;
		nbrs.temp_state[i] = 0;
		nbrs.fs[i] = 0;
		nbrs.solution[i][0] = 0;
		nbrs.solution[i][1] = 0;
		nbrs.mv[i][0] = 0;
		nbrs.mv[i][1] = 0;
		nbrs.mv[i][2] = 0;
		nbrs.mv[i][3] = 0;
		nbrs.mv[i][4] = 0;
		i++;
	}
	nbrs.total_nbrs = 0;
	nbrs.smallest = 0;
	nbrs.biggest = 0;
	nbrs.operations = 0;
	nbrs.position = 0;
	nbrs.i = 0;
	nbrs.fs_pos_sm = 0;
	nbrs.fs_pos_bg = 0;
	nbrs.a_c = 0;
	nbrs.b_c = 0;
	return (nbrs);
}

size_t	lenght(int nbr)
{
	int	i;
	size_t	ret;

	i = 0;
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

void	intake(t_nbrs *nbrs, int i, char *av)
{
	size_t	j;
	size_t	limit;

	j = 0;
	limit = ft_strlen(av);
	while (j < limit)
	{
		nbrs->a[i] = no_overflow_atoi(&av[j], nbrs);
		nbrs->a_state[i] = 1;
		if (lenght(nbrs->a[i]) != strlen_whitespace(&av[j]))
			{
				// ft_printf("%d %d\n", lenght(nbrs->a[i]), strlen_whitespace(&av[j]));
				// ft_printf("%.10s\n", &av[j]);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
		j = lenght(nbrs->a[i]) + j + 1;
		nbrs->i++;
		i++;
	}
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
			{
				ft_printf("KO\n");
				// printteri(nbrs, 500);
				// ft_printf("%d %d\n", nbrs->a[i], nbrs->a[i + 1]);
			}
			return (0);
		}
		i++;
	}
	if (a == 0)
		ft_printf("OK\n");
	return(1);
}

void printteri(t_nbrs *nbrs, int limit)
{
	int i;

	i = 0;
	ft_printf("\n");
	while ((nbrs->a_state[i] || nbrs->b_state[i]) && i < limit)
	{
		// ft_printf("%s%4d : ", CYAN, i);
		ft_printf("%4d : ",  i);
		if (nbrs->a_state[i])
		{
			ft_printf("%d",  nbrs->a[i]);
			// ft_printf("%s%d", GREEN, nbrs->a[i]);
		}
		if(!nbrs->a_state[i])
			ft_printf("\t");
		ft_printf("\t");
		if (nbrs->b_state[i])
		{
			ft_printf("%d", nbrs->b[i]);
			// ft_printf("%s%d", BLUE, nbrs->b[i]);
		}
		ft_printf("\n");
		i++;
	}
	// ft_printf("\n\t^\t^\n\t%sA\t%sB\n", GREEN, BLUE);
	ft_printf("\n^\t^\nA\tB\n");
}

int	strlen_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

void	dup_check(t_nbrs *nbrs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = how_many(&nbrs->a_state[0]);
	nbrs->total_nbrs = count;
	while (nbrs->a_state[i])
	{
		nbrs->temp[i] = nbrs->a[i];
		nbrs->temp_state[i] = 1;
		i++;
	}
	i = 0;
	while (nbrs->a_state[i])
	{
		while (nbrs->temp_state[j])
		{
			if (j == i)
				j++;
			if (nbrs->a[i] == nbrs->temp[j] && j < count)
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	solution_printer(t_nbrs *nbrs)
{
	int	i;
	int	count;

	i = 0;
	count = how_many(&nbrs->a_state[0]);
	while (i < count)
	{
		ft_printf("%d\t[%d]\n", nbrs->solution[i][0], nbrs->solution[i][1]);
		i++;
	}
}

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
