/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:45:48 by atenhune          #+#    #+#             */
/*   Updated: 2021/11/17 12:35:55 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char *) malloc (size * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
