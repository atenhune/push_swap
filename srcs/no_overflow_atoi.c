/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_overflow_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:07 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/16 22:07:28 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_overflow_atoi(const char *str, t_nbrs *nbrs)
{
	int				i;
	int				etu;
	unsigned long	ret;

	i = 0;
	ret = 0;
	etu = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			etu = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - 48;
		if (ret > 2147483647 && etu == 1)
			error_exit(nbrs, 0);
		if (ret > 2147483648 && etu == -1)
			error_exit(nbrs, 0);
	}
	return (ret * etu);
}