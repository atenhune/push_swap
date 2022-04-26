/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:24 by antti             #+#    #+#             */
/*   Updated: 2022/04/25 14:44:11 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	flags_initializer(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hashtag = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.negative = 0;
	flags.original_len = 0;
	flags.index_jump = 0;
	flags.dot = 0;
	flags.i = 0;
	flags.precision = 0;
	flags.length[0] = 0;
	flags.length[1] = 0;
	return (flags);
}

int	specifier_sorter(va_list args, char spec, t_flags flags)
{
	if (spec == 'D' || spec == 'I' || spec == 'U' || spec == 'O')
	{
		flags.length[0] = 'l';
		flags.length[1] = '\0';
		spec = spec + 32;
	}
	if ((flags.length[0] == 'l' && flags.length[1] == 'l')
		|| flags.length[0] == 'L')
		return (ll_specifiers(args, spec, flags));
	if (flags.length[0] == 'l')
		return (l_specifiers(args, spec, flags));
	return (specifiers(args, spec, flags));
}

int	index_counter(const char *s)
{
	int	ret;

	ret = 0;
	while (s[ret] && ft_isdigit(s[ret]))
		ret++;
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;
	t_flags	flags;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ++i)
		{
			flags = flags_initializer();
			i += format_reader(&str[i], &flags, args, 0);
			flags.index_jump = specifier_sorter(args, str[i], flags);
			if (flags.index_jump != -1 && ++i)
				ret += flags.index_jump;
		}
		else if (str[i] != '%')
			ret += write(1, &str[i++], 1);
		else
			i++;
	}
	va_end(args);
	return (ret);
}
