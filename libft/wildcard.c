/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:59:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:50:21 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wildcard_for_precision(t_flags *flags, va_list args)
{
	flags->precision = va_arg(args, int);
	if (flags->precision < 0)
	{
		flags->precision = 0;
		flags->dot = 0;
	}
}

void	wildcard_for_width(t_flags *flags, va_list args)
{
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	flags->index_jump = 1;
}
