/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:56:05 by atenhune          #+#    #+#             */
/*   Updated: 2021/11/18 16:26:31 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filler(char *str, int len, long n)
{
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static int	how_long(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	nb;

	nb = n;
	len = how_long(nb);
	ret = (char *) malloc(len * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		ret[0] = '0';
	ret = filler(ret, len, nb);
	return (ret);
}
