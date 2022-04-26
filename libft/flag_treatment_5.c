/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:25:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:38:54 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dot_for_numbers_minus(char *s, t_flags *flags)
{
	int	shift_1;
	int	shift_2;
	int	i;

	shift_1 = flags->precision - flags->original_len;
	shift_2 = ft_strlen(s) - flags->original_len;
	i = 0;
	if (flags->precision > flags->original_len)
	{
		ft_memmove(&s[shift_1], &s[shift_2], flags->original_len);
		while (i < shift_1)
			s[i++] = '0';
	}
	else
		ft_memmove(&s[0], &s[shift_2], flags->original_len);
	i += flags->original_len;
	while (s[i])
		s[i++] = ' ';
	flags->minus = 0;
	return (s);
}

char	*dot_for_numbers(char *s, t_flags *flags)
{
	int	i;
	int	j;

	j = flags->original_len;
	i = ft_strlen(s) - 1 - flags->original_len;
	if (flags->minus)
		return (dot_for_numbers_minus(s, flags));
	while (i >= 0)
	{
		if (j >= flags->original_len && j < flags->precision)
		{
			s[i] = '0';
			j++;
			i--;
		}
		else
		{
			s[i] = ' ';
			i--;
			j++;
		}
	}
	flags->zero = 0;
	return (s);
}

char	*dot_flag_treatment(char *s, t_flags *flags)
{
	if (flags->spec != 'f' && flags->spec != 's')
		return (dot_for_numbers(s, flags));
	if (flags->spec == 's')
	{
		return (dot_for_strings(s, flags));
	}
	return (s);
}
