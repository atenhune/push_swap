/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:51:20 by atenhune          #+#    #+#             */
/*   Updated: 2021/11/19 17:40:32 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	int				etu;
	unsigned long	ret;

	i = 0;
	ret = 0;
	etu = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			etu = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - 48;
		if (ret > 9223372036854775807 && etu == 1)
			return (-1);
		if (ret >= 9223372036854775808u && etu == -1)
			return (0);
	}
	return (ret * etu);
}
