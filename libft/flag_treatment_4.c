/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:53:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:37:59 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dot_string_helper_1(char *s, t_flags *flags, char filler)
{
	int	i;

	i = 0;
	while (i < flags->precision)
	{
		s[i] = flags->str[i];
		i++;
	}
	if (flags->width > flags->original_len)
	{
		while (s[i])
			s[i++] = filler;
	}
	if (i < flags->width)
	{
		while (i < flags->width)
			s[i++] = filler;
	}
	while (s[i])
		s[i++] = '\0';
	flags->minus = 0;
	return (s);
}

static char	*dot_string_helper_2(char *s, t_flags *flags, char filler)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flags->width > flags->precision)
	{
		while (i < flags->width)
		{
			if (i >= flags->width - flags->precision)
				s[i++] = flags->str[j++];
			else
				s[i++] = filler;
		}
	}
	else
	{
		while (i < flags->precision)
			s[i++] = flags->str[j++];
	}
	while (s[i])
		s[i++] = '\0';
	return (s);
}

char	*dot_for_strings(char *s, t_flags *flags)
{
	char	filler;

	filler = ' ';
	if (flags->zero)
		filler = '0';
	if (flags->precision < flags->original_len && flags->minus)
		return (dot_string_helper_1(s, flags, filler));
	else if (flags->precision < flags->original_len)
		return (dot_string_helper_2(s, flags, filler));
	return (s);
}
