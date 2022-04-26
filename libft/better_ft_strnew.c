/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_ft_strnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:45:48 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:30:09 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*better_ft_strnew(size_t size)
{
	char	*ret;

	ret = (char *) malloc (size * sizeof(char) + 1);
	if (ret == NULL)
		exit(0);
	ft_bzero(ret, size + 1);
	return (ret);
}
