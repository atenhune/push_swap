/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:54:43 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/25 10:17:12 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_nbrs
{
	int		a[1000];
	int		a_state[1000];
	int		b[1000];
	int		b_state[1000];
	int		temp[1000];
	int		temp_state[1000];
	int		mv[1000][5];
	int		smallest;
	int		biggest;
	int		position;
	int		i;
	char	*str;
	int		a_c;
	int		b_c;
	int		total_nbrs;
	int		selected;
	int		v;
	int		c;
}	t_nbrs;

void	printter(t_nbrs *nbrs, int a);
int		check(t_nbrs *nbrs, int a);
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
void	delete_one(int *arr, int *arr_state, t_nbrs *nbrs);
void	intake(t_nbrs *nbrs, int i, char *av);
int		lenght(int nbr);
t_nbrs	initialize(int i);
int		how_many(int *arr_state);
void	smallest(t_nbrs *nbrs, int *arr, int *arr_state);
void	biggest(t_nbrs *nbrs, int *arr, int *arr_state);
void	dup_check(t_nbrs *nbrs);
int		strlen_whitespace(char *str);
void	reset_to_smallest(t_nbrs *nbrs);
void	reset_to_big(t_nbrs *nbrs);
int		no_overflow_atoi(const char *str, t_nbrs *nbrs);
void	large_sort(t_nbrs *nbrs, int i, int j);
void	three_sort(t_nbrs *nbrs);
void	five_sort(t_nbrs *nbrs);
void	reset_to_smallest(t_nbrs *nbrs);
void	four_sort(t_nbrs *nbrs);
void	apply_moves(t_nbrs *nbrs);
void	actual_positions(t_nbrs *nbrs, int i, int j, int k);
void	error_exit(t_nbrs *nbrs, int a);
void	number_collector(t_nbrs *nbrs, int argc, char **argv);

#endif