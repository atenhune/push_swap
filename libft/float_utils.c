/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:36:58 by antti             #+#    #+#             */
/*   Updated: 2022/04/25 14:41:18 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	float_width(t_flags *flags, int len)
{
	int		i;
	int		dot;
	char	c;

	i = 0;
	dot = 1;
	if (flags->precision == 0 && !flags->hashtag)
		dot = 0;
	c = ' ';
	if (flags->zero)
		c = '0';
	while (i < flags->width - flags->precision - len - dot
		- flags->negative - flags->plus)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	float_rounder(long double nbr)
{
	long double			temp1;
	long double			comp;
	unsigned long long	temp2;

	temp1 = nbr;
	temp2 = nbr;
	comp = 0.5;
	if (temp2 != 0)
		temp1 = nbr - temp2;
	if (comp == temp1)
	{
		if (temp2 % 2 != 0)
			return (1);
		else
			return (0);
	}
	else if (temp1 < comp)
		return (0);
	else
		return (1);
	return (1);
}

int	float_zero_precision(long double nbr, t_flags *flags)
{
	unsigned long long	temp;
	int					ret;

	temp = nbr;
	ret = ull_len(temp);
	print_putnbr(temp);
	if (flags->hashtag)
		ret += write(1, ".", 1);
	return (ret);
}

long double	round_amount(t_flags *flags)
{
	long double	ret;
	int			i;

	ret = 1;
	i = 0;
	while (i < flags->precision)
	{
		ret /= 10;
		i++;
	}
	return (ret);
}

long double	is_there_need_to_round(t_flags *flags,
long double nbr, long double rounding)
{
	int					i;
	unsigned long long	temp;
	long double			ret;

	i = 0;
	temp = nbr;
	ret = nbr;
	while (i < flags->precision)
	{
		nbr = (nbr - temp) * 10;
		temp = nbr;
		i++;
	}
	if (float_rounder(nbr))
	{
		ret += rounding;
		ret -= rounding / 10;
	}
	return (ret);
}
