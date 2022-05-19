/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:48 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:43:15 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format_reader_checker(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == ' ' || c == '0'
		|| c == '.' || c == '*' || c == 'l' || c == 'h' || c == 'L'
		|| c == 'j' || c == 't' || c == 'z')
		return (1);
	return (0);
}

static int	format_precision(const char *s, t_flags *flags, va_list args)
{
	precision_catcher(&(*s), flags, args);
	if ((*(s + flags->index_jump - 1)) != '*')
		flags->precision = ft_atoi(&(*(s + flags->index_jump)));
	return (index_counter(&(*(s + flags->index_jump))));
}

int	format_reader(const char *s, t_flags *flags, va_list args, int ret)
{
	while (format_reader_checker(*s) || ft_isdigit(*s))
	{
		flags->index_jump = 0;
		flags->i = 0;
		if (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
			flag_catcher(&(*s), flags);
		else if (*s == 'l' || *s == 'h' || *s == 'L' || *s == 'j' || *s == 't'
			|| *s == 'z')
			length_catcher(&(*s), flags);
		else if (*s == '.')
			flags->i = format_precision(&(*s), flags, args);
		else if (ft_isdigit(*s))
		{
			flags->width = ft_atoi(&(*(s)));
			flags->i = index_counter(&(*(s)));
		}
		else if (*s == '*')
			wildcard_for_width(flags, args);
		s += flags->i;
		s += flags->index_jump;
		ret = ret + flags->index_jump + flags->i;
	}
	flags->i = 0;
	return (ret);
}
