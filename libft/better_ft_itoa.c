/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_ft_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:56:05 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:27:56 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filler(char *str, int len, unsigned long long int n)
{
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static int	how_long(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*better_ft_itoa(unsigned long long int n, int space)
{
	int		len;
	char	*ret;

	len = how_long(n);
	ret = better_ft_strnew(space);
	ret = filler(ret, len, n);
	return (ret);
}
