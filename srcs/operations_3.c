/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:31:56 by antti             #+#    #+#             */
/*   Updated: 2022/05/18 18:19:42 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_nbrs *nbrs, int a)
{
	rra(nbrs, 1);
	rrb(nbrs, 1);
	if (a == 0)
	{
		ft_printf("rrr\n");
		printter(nbrs, 11);
	}
}
