/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:11:05 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:47:20 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned long long nbr, const char spec, t_flags flags)
{
	int	ret;
	int	space;

	space = 20;
	if (flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	if (max_space(&flags) > space)
		space = max_space(&flags);
	flags.str = better_ft_strnew(space);
	if (nbr == 0)
		flags.hashtag = 0;
	if (!(nbr == 0 && flags.precision == 0 && flags.dot))
		hex_creator(nbr, spec, &flags);
	flags.original_len = ft_strlen(flags.str);
	flags.str = flag_trafficker(flags.str, &flags);
	if (flags.spec == 'p')
		flags.str = pointer_addon(flags.str, &flags, 0);
	ret = write(1, &flags.str[0], ft_strlen(flags.str));
	ft_memdel((void *)&flags.str);
	return (ret);
}

int	print_pointer(unsigned long long pointer, t_flags flags)
{
	int	ret;

	ret = print_hex(pointer, 'x', flags);
	return (ret);
}

int	print_octal(unsigned long long int nbr, t_flags flags)
{
	int	ret;
	int	space;

	space = 25;
	if (flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	if (max_space(&flags) > space)
		space = max_space(&flags);
	flags.str = better_ft_strnew(space);
	if (!(nbr == 0 && flags.precision == 0 && flags.dot))
		octal_creator(nbr, &flags);
	if ((nbr == 0 && flags.dot && flags.precision != 0)
		|| (nbr == 0 && !flags.dot))
		flags.hashtag = 0;
	flags.original_len = ft_strlen(flags.str);
	flags.str = flag_trafficker(flags.str, &flags);
	ret = write(1, &flags.str[0], ft_strlen(flags.str));
	ft_memdel((void *)&flags.str);
	return (ret);
}
