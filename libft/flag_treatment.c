/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:58 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:39:29 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_minus_space(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

static char	*negative_helper(char *s, t_flags *flags)
{
	if (!flags->zero)
	{
		if (flags->original_len >= flags->width)
			ft_memmove(&s[1], &s[0], ft_strlen(s));
		else
			ft_memmove(&s[1], &s[0], ft_strlen(s) - 1);
	}
	else if (flags->original_len >= flags->width)
		ft_memmove(&s[1], &s[0], ft_strlen(s));
	s[0] = '-';
	return (s);
}

char	*if_negative(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->width > flags->precision)
	{
		while (s[i] == ' ')
			i++;
		if (i == 0)
			return (negative_helper(s, flags));
		else
			s[i - 1] = '-';
	}
	else
	{
		ft_memmove(&s[1], &s[0], ft_strlen(s));
		s[0] = '-';
	}
	return (s);
}

void	flag_modifier(t_flags *flags)
{
	if (flags->spec != 'o' && flags->spec != 'x' && flags->spec != 'X')
		flags->hashtag = 0;
	if (flags->minus)
		flags->zero = 0;
	if (flags->spec == '%')
	{
		flags->space = 0;
		flags->dot = 0;
		flags->precision = 0;
	}
	if (flags->spec == 'c')
	{
		flags->space = 0;
		flags->plus = 0;
		flags->dot = 0;
		flags->precision = 0;
	}
	if (flags->spec == 's')
		flags->space = 0;
	if (flags->spec == 'p')
	{
		flags->space = 0;
		flags->plus = 0;
	}
}

char	*flag_trafficker(char *s, t_flags *flags)
{
	flag_modifier(flags);
	s = width_treatment(s, flags);
	s = precision_treatment(s, flags);
	if (flags->dot)
		s = dot_flag_treatment(s, flags);
	if (flags->minus)
		s = minus_flag_treatment(s, flags);
	if (flags->zero && !flags->minus)
		s = zero_flag_treatment(s, flags);
	if (flags->plus)
		s = plus_flag_treatment(s, flags);
	if (flags->space && !flags->plus)
		s = space_flag_treatment(s, flags);
	if (flags->hashtag)
		s = hashtag_flag_treatment(s, flags);
	if (flags->negative)
		s = if_negative(s, flags);
	return (s);
}
