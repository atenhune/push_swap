/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:17:00 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:36:17 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*space_flag_treatment(char *s, t_flags *flags)
{
	if (flags->plus == 1 || flags->negative == 1)
		return (s);
	else if (flags->precision > flags->width
		|| (flags->precision < flags->original_len > flags->width))
	{
		ft_memmove(&s[1], &s[0], ft_strlen(s));
		s[0] = ' ';
	}
	else if ((flags->original_len < flags->width > flags->precision))
		s[0] = ' ';
	return (s);
}

static char	*octal_hashtag(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->precision <= flags->original_len)
	{
		if (s[0] != ' ')
		{
			ft_memmove(&s[1], &s[0], flags->original_len);
			s[0] = '0';
		}
		else
		{
			while (s[i] == ' ')
				i++;
			s[i - 1] = '0';
		}
	}
	return (s);
}

static char	*hashtag_helper(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	if (i < 2)
	{
		ft_memmove(&s[i + 1], &s[i], ft_strlen(&s[i]));
		s[0] = '0';
		s[1] = flags->spec;
	}
	else
	{
		s[i - 2] = '0';
		s[i - 1] = flags->spec;
	}
	return (s);
}

char	*hashtag_flag_treatment(char *s, t_flags *flags)
{
	if (flags->spec == 'o')
		return (octal_hashtag(s, flags));
	if (s[0] == ' ')
		return (hashtag_helper(s, flags));
	else if (flags->precision <= flags->original_len)
	{
		ft_memmove(&s[2], &s[0], flags->original_len);
		s[0] = '0';
		s[1] = flags->spec;
	}
	else
	{
		ft_memmove(&s[2], &s[0], ft_strlen(s));
		s[0] = '0';
		s[1] = flags->spec;
	}
	return (s);
}
