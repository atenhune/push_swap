/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:47:14 by antti             #+#    #+#             */
/*   Updated: 2021/11/18 16:05:57 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	beginning(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	return (i);
}

static int	end(const char *s, int len)
{
	int	i;

	i = 0;
	while (s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == ' ')
	{
		len--;
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s)
{
	int		len;
	int		i;
	int		new_len;
	char	*ret;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = beginning(s);
	new_len = len - (i + end(s, len));
	if (new_len < 0)
		new_len = 0;
	ret = (char *) malloc(new_len * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	len = 0;
	while (len < new_len)
	{
		ret[len] = s[i];
		len++;
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
