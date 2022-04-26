/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:55:21 by antti             #+#    #+#             */
/*   Updated: 2022/04/25 14:48:17 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_chars(int c, t_flags flags)
{
	char	*str;
	int		ret;

	str = better_ft_strnew(max_space(&flags));
	str[0] = c;
	flags.original_len = 1;
	str = flag_trafficker(str, &flags);
	if (c == 0 && flags.minus)
		ret = write(1, &str[0], ft_strlen(&str[1]) + 1);
	else if (c == 0)
		ret = write(1, &str[0], ft_strlen(str) + 1);
	else
		ret = write(1, &str[0], ft_strlen(str));
	ft_memdel((void *)&str);
	return (ret);
}

int	print_str(char *str, t_flags flags)
{
	int		ret;
	char	*n_str;

	flags.original_len = ft_strlen(str);
	flags.str = better_ft_strnew(max_space(&flags));
	n_str = better_ft_strnew(max_space(&flags));
	if (str == NULL)
	{
		ft_strcpy(flags.str, "(null)");
		ft_strcpy(n_str, "(null)");
	}
	else
	{
		ft_strcpy(flags.str, str);
		ft_strcpy(n_str, str);
	}
	n_str = flag_trafficker(n_str, &flags);
	ret = write(1, &n_str[0], ft_strlen(n_str));
	ft_memdel((void *)&flags.str);
	ft_memdel((void *)&n_str);
	return (ret);
}

int	print_percent(char *str, t_flags flags)
{
	char	*s;
	int		ret;

	s = better_ft_strnew(max_space(&flags));
	flags.original_len = ft_strlen(str);
	ft_strcpy(s, str);
	s = flag_trafficker(s, &flags);
	ret = write(1, &s[0], ft_strlen(s));
	ft_memdel((void *)&s);
	return (ret);
}

int	print_signed_nbr(signed long long nbr, t_flags flags)
{
	int					ret;
	char				*str;
	unsigned long long	n;

	if (flags.length[0] == 'h')
		nbr = signed_hh_converter(nbr, &flags);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		flags.negative = 1;
	}
	n = nbr;
	flags.original_len = ull_len(n);
	str = better_ft_itoa(n, max_space(&flags));
	if (nbr == 0 && flags.precision == 0 && flags.dot)
	{
		str[0] = '\0';
		flags.original_len = 0;
	}
	str = flag_trafficker(str, &flags);
	ret = write(1, &str[0], ft_strlen(str));
	ft_memdel((void *)&str);
	return (ret);
}

int	print_unsigned_nbr(unsigned long long nbr, t_flags flags)
{
	char	*str;
	int		ret;

	if (flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	flags.space = 0;
	flags.plus = 0;
	flags.original_len = ull_len(nbr);
	str = better_ft_itoa(nbr, max_space(&flags));
	if (nbr == 0 && flags.precision == 0 && flags.dot)
	{
		str[0] = '\0';
		flags.original_len = 0;
	}
	str = flag_trafficker(str, &flags);
	ret = write(1, &str[0], ft_strlen(str));
	ft_memdel((void *)&str);
	return (ret);
}
