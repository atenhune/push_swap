/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:44:54 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:33:10 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	signed_hh_converter(long long nbr, t_flags *flags)
{
	signed char	a;
	short int	b;

	a = 0;
	b = 0;
	if (flags->length[0] == 'h' && flags->length[1] == 'h')
	{
		a = nbr;
		nbr = a;
	}
	else
	{
		b = nbr;
		nbr = b;
	}
	return (nbr);
}

unsigned long long	unsigned_hh_converter(unsigned long long nbr,
t_flags *flags)
{
	unsigned char		a;
	unsigned short int	b;

	a = 0;
	b = 0;
	if (flags->length[0] == 'h' && flags->length[1] == 'h')
	{
		a = nbr;
		nbr = a;
	}
	else
	{
		b = nbr;
		nbr = b;
	}
	return (nbr);
}
