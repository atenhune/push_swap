/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:48:00 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:40:30 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flag_switcher(t_flags *flags)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->negative)
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if (flags->precision == 0 && flags->dot)
		return (0);
	return (1);
}
