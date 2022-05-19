/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:39:14 by antti             #+#    #+#             */
/*   Updated: 2021/11/22 12:44:31 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*ret;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	ret = (char *) malloc(len * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
