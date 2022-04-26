/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:35:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/26 13:37:54 by atenhune         ###   ########.fr       */
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
		nbrs->temp[i] = arr[i + 1];
		i++;
	}
	arr_state[i - 1] = 0;
	i = 0;
	while (arr_state[i])
	{
		arr[i] = nbrs->temp[i];
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