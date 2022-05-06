/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:54:43 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/06 16:31:12 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>

# include <stdio.h>

typedef struct s_nbrs
{
	int		a[1000];
	int		a_state[1000];
	int		b[1000];
	int		b_state[1000];
	int		temp[1000];
	int		temp_state[1000];
	int		temp2[1000];
	int		temp2_state[1000];
	int		smallest;
	int		biggest;
	int		position;
	int		operations;
	int		i;
	char	*str;
}	t_nbrs;

void	sa(t_nbrs *nbrs, int a);
void	sb(t_nbrs *nbrs, int a);
void	ss(t_nbrs *nbrs, int a);
void	pa(t_nbrs *nbrs, int a);
void	pb(t_nbrs *nbrs, int a);
void	ra(t_nbrs *nbrs, int a);
void	rb(t_nbrs *nbrs, int a);
void	rr(t_nbrs *nbrs, int a);
void	rra(t_nbrs *nbrs, int a);
void	rrb(t_nbrs *nbrs, int a);
void	rrr(t_nbrs *nbrs, int a);
void	delete(int *arr, int *arr_state, t_nbrs *nbrs);
void	intake(t_nbrs *nbrs, int i, char *av);
size_t	lenght(int nbr);
t_nbrs	initialize(int argc);
int		how_many(int *arr_state);
void	smallest(t_nbrs *nbrs, int *arr, int *arr_state);
void	biggest(t_nbrs *nbrs, int *arr, int *arr_state);
void	split(t_nbrs *nbrs);
void	sort_a(t_nbrs *nbrs);
void	sort_b(t_nbrs *nbrs);
void	merge(t_nbrs *nbrs);
void	reset(t_nbrs *nbrs);
void	split_big_small(t_nbrs *nbrs);
void	no_sort_b(t_nbrs *nbrs);
int		check(t_nbrs *nbrs, int a);
void	testi_aa(t_nbrs *nbrs);

void	testi_a(t_nbrs *nbrs);
void	testi_b(t_nbrs *nbrs);
void printteri(t_nbrs *nbrs);


#endif