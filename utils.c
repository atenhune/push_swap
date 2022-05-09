/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:35:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/09 17:33:56 by atenhune         ###   ########.fr       */
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
		i++;
	}
	nbrs.smallest = 0;
	nbrs.biggest = 0;
	nbrs.operations = 0;
	nbrs.position = 0;
	nbrs.i = 0;
	nbrs.fs[0] = 0;
	nbrs.fs[1] = 0;
	nbrs.fs[2] = 0;
	nbrs.fs[3] = 0;
	nbrs.fs[4] = 0;
	nbrs.fs[5] = 0;
	nbrs.fs[6] = 0;
	nbrs.fs[7] = 0;
	nbrs.fs[8] = 0;
	nbrs.fs[9] = 0;
	nbrs.fs[10] = 0;
	nbrs.fs[11] = 0;
	nbrs.fs[12] = 0;
	nbrs.fs[13] = 0;
	nbrs.fs[14] = 0;
	nbrs.fs[15] = 0;
	nbrs.fs_state[0] = 0;
	nbrs.fs_state[1] = 0;
	nbrs.fs_state[2] = 0;
	nbrs.fs_state[3] = 0;
	nbrs.fs_state[4] = 0;
	nbrs.fs_state[5] = 0;
	nbrs.fs_state[6] = 0;
	nbrs.fs_state[7] = 0;

	return (nbrs);
}

size_t	lenght(int nbr)
{
	int	i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (nbr < 0)
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
		nbrs->a[i] = ft_atoi(&av[j]);
		nbrs->a_state[i] = 1;
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
				ft_printf("KO\n");
			return (0);
		}
		i++;
	}
	if (a == 0)
		ft_printf("OK\n");
	return(1);
}

void printteri(t_nbrs *nbrs)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (nbrs->a_state[i] || nbrs->b_state[i])
	{
		if (nbrs->a_state[i])
			ft_printf("%d", nbrs->a[i]);
		ft_printf("\t");
		if (nbrs->b_state[i])
			ft_printf("%d", nbrs->b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n^\t^\nA\tB\n");
}





