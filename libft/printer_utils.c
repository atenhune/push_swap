/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:04:59 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:45:50 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max_space(t_flags *flags)
{
	if (flags->original_len >= flags->width
		&& flags->original_len >= flags->precision)
		return (flags->original_len + 2);
	if (flags->width >= flags->precision)
		return (flags->width + 2);
	return (flags->precision + 2);
}

int	ull_len(unsigned long long nbr)
{
	int	ret;

	ret = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}

char	*pointer_addon(char *s, t_flags *flags, int i)
{
	if (flags->width > flags->precision && flags->width > flags->original_len)
	{
		while (s[i] == ' ')
			i++;
		if (i == 0)
			ft_memmove(&s[2], &s[0], strlen_minus_space(s));
		if (i == 1)
			ft_memmove(&s[2], &s[1], strlen_minus_space(s));
		if (i > 1)
		{
			s[i - 2] = '0';
			s[i - 1] = 'x';
			return (s);
		}
		s[0] = '0';
		s[1] = 'x';
	}
	else
	{
		ft_memmove(&s[2], &s[0], ft_strlen(s));
		s[0] = '0';
		s[1] = 'x';
	}
	return (s);
}

void	octal_creator(unsigned long long int nbr, t_flags *flags)
{
	if (nbr >= 8)
	{
		octal_creator(nbr / 8, flags);
		octal_creator(nbr % 8, flags);
	}
	else
		flags->str[flags->i++] = nbr + '0';
}

void	hex_creator(unsigned long long nbr, const char spec, t_flags *flags)
{
	if (nbr >= 16)
	{
		hex_creator(nbr / 16, spec, flags);
		hex_creator(nbr % 16, spec, flags);
	}
	else
	{
		if (nbr <= 9)
			flags->str[flags->i++] = nbr + '0';
		else
		{
			if (spec == 'x')
				flags->str[flags->i++] = (nbr - 10 + 'a');
			if (spec == 'X')
				flags->str[flags->i++] = (nbr - 10 + 'A');
		}
	}
}
