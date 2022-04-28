/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:54:43 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/28 14:33:14 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_nbrs
{
	int	a[1000];
	int	a_state[1000];
	int	b[1000];
	int	b_state[1000];
	int	temp[1000];
	int	smallest;
	int	biggest;
	int	position;
	int	operations;
}	t_nbrs;

void	sa(t_nbrs *nbrs);
void	sb(t_nbrs *nbrs);
void	ss(t_nbrs *nbrs);
void	pa(t_nbrs *nbrs);
void	pb(t_nbrs *nbrs);
void	ra(t_nbrs *nbrs);
void	rb(t_nbrs *nbrs);
void	rr(t_nbrs *nbrs);
void	rra(t_nbrs *nbrs);
void	rrb(t_nbrs *nbrs);
void	rrr(t_nbrs *nbrs);
void	delete(int *arr, int *arr_state, t_nbrs *nbrs);
int		how_many(int *arr_state);
void	smallest(t_nbrs *nbrs, int *arr, int *arr_state);
void	biggest(t_nbrs *nbrs);
void	split(t_nbrs *nbrs);
void	sort_a(t_nbrs *nbrs);
void	sort_b(t_nbrs *nbrs);
void	merge(t_nbrs *nbrs);
void	reset(t_nbrs *nbrs);

void	testi_a(t_nbrs *nbrs);
void	testi_b(t_nbrs *nbrs);


#endif