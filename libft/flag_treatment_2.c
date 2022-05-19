/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:04 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:35:01 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*zero_flag_treatment(char *s, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->original_len >= flags->width)
		return (s);
	while (i < flags->width - flags->original_len)
		s[i++] = '0';
	return (s);
}

char	*plus_flag_treatment(char *s, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->negative == 1)
		return (s);
	while (!ft_isdigit(s[i]))
		i++;
	if (i == 0)
	{
		if (!(flags->zero && flags->width > flags->original_len))
			ft_memmove(&s[1], &s[0], strlen_minus_space(s));
		s[0] = '+';
	}
	else
		s[i - 1] = '+';
	return (s);
}

char	*width_treatment(char *s, t_flags *flags)
{
	int		i;
	int		j;

	i = 0;
	j = flags->width - flags->original_len;
	if (flags->width > flags->original_len)
	{
		ft_memmove(&s[j], &s[0], flags->original_len);
		while (i < j)
			s[i++] = ' ';
	}
	return (s);
}

char	*precision_treatment(char *s, t_flags *flags)
{
	int		from;
	int		to;
	int		i;

	from = flags->width - flags->original_len;
	to = flags->precision - flags->original_len;
	i = 0;
	if (flags->precision <= flags->original_len || flags->precision
		<= flags->width || flags->spec == 's')
		return (s);
	if (from < 0)
		from = 0;
	ft_memmove(&s[to], &s[from], flags->original_len);
	while (i < to)
		s[i++] = '0';
	return (s);
}

char	*minus_flag_treatment(char *s, t_flags *flags)
{
	int	i;

	i = flags->original_len;
	if (flags->original_len > flags->width)
		return (s);
	ft_memmove(&s[0], &s[flags->width
		- flags->original_len], flags->original_len);
	while (i < flags->width)
		s[i++] = ' ';
	return (s);
}
