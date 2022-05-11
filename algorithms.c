/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:37:30 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/11 18:17:06 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./includes/push_swap.h"

void	split(t_nbrs *nbrs)
{
	int count;

	count = how_many(&nbrs->a_state[0]);
	count /= 2;
	// ft_printf("%d\n", count);
	// exit(0);
	while (count > 0)
	{
		pb(nbrs, 0);
		count--;
		nbrs->operations++;
	}
}

void	r_temp(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->temp_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == 0)
			nbrs->temp2[count - 1] = nbrs->temp[i];
		else
			nbrs->temp2[i - 1] = nbrs->temp[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->temp[i] = nbrs->temp2[i];
		i++;
	}

}

void	mid_nbr(t_nbrs *nbrs, int count)
{
	int	i;

	i = 0;
	while(nbrs->a_state[i])
	{
		nbrs->temp[i] = nbrs->a[i];
		nbrs->temp_state[i] = 1;
		i++;
	}
	i = 0;
	while (i < count)
	{
		smallest(nbrs, nbrs->temp, nbrs->temp_state);
		while (nbrs->temp[0] != nbrs->smallest)
			r_temp(nbrs);
		// nbrs->temp2[i] = nbrs->temp[0];
		delete(&nbrs->temp[0], &nbrs->temp_state[0], nbrs);
		i++;
	}
	smallest(nbrs, nbrs->temp, nbrs->temp_state);
	// ft_printf("[%d]\n", nbrs->smallest);
}

void	split_big_small(t_nbrs *nbrs)
{
	int count;
	int	mid;
	int	i;

	count = how_many(&nbrs->a_state[0]) / 2;
	mid_nbr(nbrs, count);
	mid = nbrs->smallest;
	i = 0;
	// ft_printf("%d\n", count);
	// exit(0);
	while (count > 0)
	{
		if (nbrs->a[0] < mid)
		{
			pb(nbrs, 0);
			count--;
		}
		else
			ra(nbrs, 0);
		// nbrs->operations++;
	}
}

void	sort_a(t_nbrs *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs->a_state[i])
	{
		if (nbrs->a[i] > nbrs->a[i + 1] && nbrs->a_state[i] && nbrs->a_state[i + 1])
		{
			if (i != 0)
			{
				j = 0;
				while (j < i)
				{
					ra(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				sa(nbrs, 0);
				nbrs->operations++;
				j = 0;
				while (j < i)
				{
					rra(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				i = -1;
			}
			else
			{
				sa(nbrs, 0);
				nbrs->operations++;
				i = -1;
			}
		}
		i++;
	}
}

void	sort_b(t_nbrs *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs->b_state[i])
	{
		if (nbrs->b[i] > nbrs->b[i + 1] && nbrs->b_state[i] && nbrs->b_state[i + 1])
		{
			if (i != 0)
			{
				j = 0;
				while (j < i)
				{
					rb(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				sb(nbrs, 0);
				nbrs->operations++;
				j = 0;
				while (j < i)
				{
					rrb(nbrs, 0);
					nbrs->operations++;
					j++;
				}
				i = -1;
			}
			else
			{
				sb(nbrs, 0);
				nbrs->operations++;
				i = -1;
			}
		}
		i++;
	}
}

void	merge(t_nbrs *nbrs)
{
	int	count;
	int	i;

	count = how_many(&nbrs->a_state[0]);
	i = 0;
	while (nbrs->b_state[0])
	{
		if (nbrs->a[0] > nbrs->b[0])
		{
			pa(nbrs, 0);
			nbrs->operations++;
			ra(nbrs, 0);
			nbrs->operations++;
		}
		else
		{
			if (i == count)
			{
				pa(nbrs, 0);
				nbrs->operations++;
				ra(nbrs, 0);
				nbrs->operations++;
			}
			else
			{
				ra(nbrs, 0);
				nbrs->operations++;
				i++;
			}
		}
	}
}

void	reset(t_nbrs *nbrs)
{
	int limit;

	limit = how_many(&nbrs->a_state[0]) / 2;
	while (nbrs->a[0] != nbrs->smallest)
	{
		if (nbrs->position < limit)
		{
			ra(nbrs, 0);
			nbrs->operations++;
		}
		else
		{
			rra(nbrs, 0);
			nbrs->operations++;
		}
	}
}

void	reset_to_big(t_nbrs *nbrs)
{
	int limit;

	limit = how_many(&nbrs->b_state[0]) / 2;
	while (nbrs->b[0] != nbrs->biggest)
	{
		if (nbrs->position < limit)
		{
			rb(nbrs, 0);
			nbrs->operations++;
		}
		else
		{
			rrb(nbrs, 0);
			nbrs->operations++;
		}
	}
}

void	testi_a(t_nbrs *nbrs)
{
	int	limit;
	int	count;

	count = how_many(&nbrs->a_state[0]);
	while (nbrs->a_state[0])
	{
		smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
		limit = how_many(&nbrs->a_state[0]) / 2;
		while (nbrs->a[0] != nbrs->smallest)
		{
			if (nbrs->position <= limit)
				ra(nbrs, 0);
			else
				rra(nbrs, 0);
			nbrs->operations++;
		}
		pb(nbrs, 0);
		nbrs->operations++;
	}
	while (count > 0)
	{
		pa(nbrs, 0);
		nbrs->operations++;
		count--;
	}
}

void	testi_b(t_nbrs *nbrs)
{
	int	limit;
	int	count;

	count = how_many(&nbrs->b_state[0]);
	while (nbrs->b_state[0])
	{
		smallest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
		limit = how_many(&nbrs->b_state[0]) / 2;
		while (nbrs->b[0] != nbrs->smallest)
		{
			if (nbrs->position <= limit)
				rb(nbrs, 0);
			else
				rrb(nbrs, 0);
			nbrs->operations++;
		}
		pa(nbrs, 0);
		nbrs->operations++;
	}
	while (count > 0)
	{
		pb(nbrs, 0);
		nbrs->operations++;
		count--;
	}
}

void	no_sort_b(t_nbrs *nbrs)
{
	int	i;
	int limit;

	i = 0;
	while (nbrs->b_state[i])
	{
		biggest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
		limit = how_many(&nbrs->b_state[0]) / 2;
		while (nbrs->b[0] != nbrs->biggest)
		{
			if (nbrs->position < limit)
			{
				rb(nbrs, 0);
				nbrs->operations++;
			}
			else
			{
				rrb(nbrs, 0);
				nbrs->operations++;
			}
		}
		pa(nbrs, 0);
		nbrs->operations++;
	}
}

void	testi_aa(t_nbrs *nbrs)
{
	int	i;
	int	limit;

	i = 0;
	limit = how_many(&nbrs->a_state[0]) - 1;
	smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
	reset(nbrs);
	while (!check(nbrs, 1))
	{
		while (i < limit)
		{
			if (nbrs->a[0] > nbrs->a[1])
				sa(nbrs, 0);
			else
			{
				ra(nbrs, 0);
				i++;
			}
		}
		i = 0;
		reset(nbrs);
	}
}

void testi_aaa(t_nbrs *nbrs)
{
	int	i;
	int	count;
	while (nbrs->a_state[0])
	{
		smallest(nbrs, &nbrs->a[0], &nbrs->a_state[0]);
		reset(nbrs);
		pb(nbrs, 0);
		count++;
	}
	while (nbrs->b_state[0])
		pa(nbrs, 0);
}

void	rt(t_nbrs *nbrs)
{
	int	i;
	int	count;

	count = how_many(&nbrs->temp_state[0]);
	if (count < 2)
		return ;
	i = count - 1;
	while (i >= 0)
	{
		if (i == 0)
			nbrs->temp2[count - 1] = nbrs->temp[i];
		else
			nbrs->temp2[i - 1] = nbrs->temp[i];
		i--;
	}
	i = 0;
	while (i < count)
	{
		nbrs->temp[i] = nbrs->temp2[i];
		i++;
	}
}

void	four_smallest(t_nbrs *nbrs, int a)
{
	int	i;
	int	count;

	count = how_many(&nbrs->a_state[0]);
	while (nbrs->a_state[i])
	{
		nbrs->temp[i] = nbrs->a[i];
		nbrs->temp_state[i] = 1;
		i++;
	}
	i = 0;
	while (i < a && nbrs->temp_state[0])
	{
		smallest(nbrs, &nbrs->temp[0], &nbrs->temp_state[0]);
		nbrs->fs[i] = nbrs->smallest;
		while (nbrs->temp[0] != nbrs->smallest)
			rt(nbrs);
		delete(&nbrs->temp[0], &nbrs->temp_state[0], nbrs);
		i++;
	}
}


void	four_smallest_b(t_nbrs *nbrs, int a)
{
	int	i;
	int	count;

	count = how_many(&nbrs->b_state[0]);
	while (nbrs->b_state[i])
	{
		nbrs->temp[i] = nbrs->b[i];
		nbrs->temp_state[i] = 1;
		i++;
	}
	i = 0;
	while (i < a && nbrs->temp_state[0])
	{
		smallest(nbrs, &nbrs->temp[0], &nbrs->temp_state[0]);
		nbrs->fs[i] = nbrs->smallest;
		while (nbrs->temp[0] != nbrs->smallest)
			rt(nbrs);
		delete(&nbrs->temp[0], &nbrs->temp_state[0], nbrs);
		i++;
	}
}

int is_fs(t_nbrs *nbrs, int nbr, int a)
{
	int	i;
	// int	count;

	i = 0;
	// count = how_many(&nbrs->a_state[0]);
	while (i < a)
	{
		if (nbr == nbrs->fs[i])
			return (1);
		i++;
	}
	return(0);
}

void	split_four(t_nbrs *nbrs, int a) // 5158
{
	int	i;

	// i = 0;
	while (nbrs->a_state[0])
	{
		four_smallest(nbrs, a);
		while(!is_fs(nbrs, nbrs->a[0], a))
		{
			ra(nbrs, 0);
			nbrs->operations++;
			// if (up_or_down(nbrs, a))
			// 	rra(nbrs, 0);
			// else
			// 	ra(nbrs, 0);
			// nbrs->operations++;
		}
		pb(nbrs, 0);
		nbrs->operations++;
		// i++;
		// i = 0;
	}
}

void	split_test(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	while (nbrs->a_state[0])
	{
		four_smallest(nbrs, a);
		while (i < a)
		{
			while(!is_fs(nbrs, nbrs->a[0], a))
			{
				ra(nbrs, 0);
				nbrs->operations++;
			}
			pb(nbrs, 0);
			nbrs->operations++;
			i++;
		}
		i = 0;
	}
}

void	split_test_b(t_nbrs *nbrs, int a)
{
	int	i;

	i = 0;
	while (nbrs->b_state[0])
	{
		four_smallest_b(nbrs, a);
		while (i < a)
		{
			while(!is_fs(nbrs, nbrs->b[0], a))
			{
				rb(nbrs, 0);
				nbrs->operations++;
			}
			pa(nbrs, 0);
			nbrs->operations++;
			i++;
		}
		i = 0;
	}
}

void	split_four_b(t_nbrs *nbrs, int a) // 5158
{
	int	i;

	// i = 0;
	while (nbrs->b_state[0])
	{
		four_smallest_b(nbrs, a);
		while(!is_fs(nbrs, nbrs->b[0], a))
		{
			rb(nbrs, 0);
			nbrs->operations++;
			// if (up_or_down(nbrs, a))
			// 	rra(nbrs, 0);
			// else
			// 	ra(nbrs, 0);
			// nbrs->operations++;
		}
		pa(nbrs, 0);
		nbrs->operations++;
		// i++;
		// i = 0;
	}
}

void	no_sort_four(t_nbrs *nbrs) // 2490
{
	int i;
	// int j;

	i = 0;
	// j = 0;
	while (nbrs->b_state[0])
	{
		biggest(nbrs, &nbrs->b[0], &nbrs->b_state[0]);
		// while (nbrs->b[0] != nbrs->biggest)
		// {
		// 	rb(nbrs, 0);
		// 	nbrs->operations++;
		// 	i++;
		// }
		reset_to_big(nbrs);
		pa(nbrs, 0);
		nbrs->operations++;
		// while (i != 0)
		// {
		// 	rrb(nbrs, 0);
		// 	nbrs->operations++;
		// 	i--;
		// }
	}
}


int	up_or_down(t_nbrs *nbrs, int a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbrs->a_state[i])
	{
		if (is_fs(nbrs, nbrs->a[i], a))
		{
			if (j == 0)
			{
				nbrs->fs_pos_sm = i;
				j = 1;
			}
			nbrs->fs_pos_bg = i;
		}
		i++;
	}
	// printf("%d %d %d\n", nbrs->fs_pos_sm, nbrs->fs_pos_bg, i);
	// exit(0);
	if (how_many(&nbrs->a_state[0]) - nbrs->fs_pos_bg < nbrs->fs_pos_sm)
	{
		// nbrs->position++;
		return (1);
	}

	// nbrs->position++;
	return (0);
}

