/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catchers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:21:48 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:30:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	precision_catcher(const char *s, t_flags *flags, va_list args)
{
	int	ret;

	ret = 0;
	while (*s == '.' || *s == '*')
	{
		if (*s == '.')
		{
			flags->dot = 1;
			ret++;
		}
		if (*s == '*')
		{
			ret++;
			wildcard_for_precision(flags, args);
			break ;
		}
		s++;
	}
	flags->index_jump = ret;
}

void	flag_catcher(const char *s, t_flags *flags)
{
	int	ret;

	ret = 0;
	while (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
	{
		if (*s == '+')
			flags->plus = 1;
		if (*s == '-')
			flags->minus = 1;
		if (*s == '#')
			flags->hashtag = 1;
		if (*s == ' ')
			flags->space = 1;
		if (*s == '0')
			flags->zero = 1;
		if (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
			ret++;
		s++;
	}
	flags->index_jump = ret;
}

void	length_helper(const char *s, t_flags *flags)
{
	if (*s == 'l' && flags->length[0] == 'l')
		flags->length[1] = *s;
	else if (*s == 'l')
		flags->length[0] = *s;
	else if (flags->length[0] == 'h' && *s == 'h')
		flags->length[1] = *s;
	else if (flags->length[0] != 'l' && *s == 'h')
		flags->length[0] = *s;
	else if (*s == 'L')
		flags->length[0] = 'L';
}

void	length_catcher(const char *s, t_flags *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flags->index_jump = 0;
	while (*s == 'l' || *s == 'h' || *s == 'L' || *s == 'j'
		|| *s == 't' || *s == 'z')
	{
		if ((*s != 'z' || *s != 'j' || *s != 't') && j == 0)
			length_helper(s, flags);
		if (*s == 'z' || *s == 'j' || *s == 't')
		{
			flags->length[0] = 'l';
			flags->length[1] = 'l';
			j++;
		}
		s++;
		i++;
	}
	flags->index_jump = i;
}
