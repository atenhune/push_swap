/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:11:15 by antti             #+#    #+#             */
/*   Updated: 2022/04/25 14:42:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	float_helper1(t_flags *flags, int len, int dot, int ret)
{
	dot = flag_switcher(flags);
	if (flags->negative && (flags->width <= len + flags->precision + dot
			|| flags->minus || flags->zero))
		ret += write(1, "-", 1);
	if (flags->plus && (flags->width <= len + flags->precision + dot
			|| flags->minus || flags->zero))
		ret += write(1, "+", 1);
	if (flags->space)
	{
		ret += write(1, " ", 1);
		flags->width--;
	}
	if (flags->width > len + flags->precision + dot && !flags->minus)
		ret += float_width(flags, len);
	if (flags->negative && flags->width > len + flags->precision + dot
		&& !flags->minus && !flags->zero)
		ret += write(1, "-", 1);
	if (flags->plus && flags->width > len + flags->precision + dot
		&& !flags->minus && !flags->zero)
		ret += write(1, "+", 1);
	return (ret);
}

static int	float_helper2(t_flags *flags, unsigned long long temp,
long double nbr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < flags->precision)
	{
		nbr = (nbr - temp) * 10;
		temp = nbr;
		print_putnbr(temp);
		i++;
	}
	ret += i;
	return (ret);
}

static int	float_helper3(t_flags *flags,
unsigned long long temp, long double nbr, int len)
{
	int	ret;

	ret = 0;
	print_putnbr(temp);
	ret += write(1, ".", 1);
	ret += float_helper2(flags, temp, nbr);
	if (flags->minus)
		ret += float_width(flags, len);
	return (ret);
}

static int	printer_zero_precision(long double nbr, t_flags *flags,
int ret, int len)
{
	ret -= len;
	ret += float_zero_precision(nbr, flags);
	if (flags->minus)
		ret += float_width(flags, len);
	return (ret);
}

int	float_printer(long double nbr, t_flags flags)
{
	unsigned long long	temp;
	int					len;
	int					ret;
	long double			rounding;

	if (1 / nbr < 0)
	{
		nbr = nbr * -1;
		flags.negative = 1;
	}
	if (!flags.dot)
		flags.precision = 6;
	rounding = round_amount(&flags);
	nbr = is_there_need_to_round(&flags, nbr, rounding);
	temp = nbr;
	len = ull_len(temp);
	ret = len;
	ret += float_helper1(&flags, len, 0, 0);
	if (flags.precision == 0)
		return (printer_zero_precision(nbr, &flags, ret, len));
	ret += float_helper3(&flags, temp, nbr, len);
	return (ret);
}
