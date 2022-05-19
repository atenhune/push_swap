/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:12:35 by atenhune          #+#    #+#             */
/*   Updated: 2021/11/22 13:19:02 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (((char *)s)[i] != '\0')
			i++;
		return (&((char *)s)[i]);
	}
	i = ft_strlen(s) - 1;
	while (i >= 0 && ((char *)s)[i] != c)
	{
		i--;
	}
	if (i == -1)
		return (NULL);
	else
		return (&((char *)s)[i]);
}
