/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:54:43 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/26 14:23:50 by atenhune         ###   ########.fr       */
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


#endif