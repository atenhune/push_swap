/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:50:58 by antti             #+#    #+#             */
/*   Updated: 2021/11/18 15:55:04 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			j++;
		if (s[i] != c && s[i - 1] == c)
			j++;
		i++;
	}
	return (j);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
		{
			return (i);
		}
	}
	return (i);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = (char **) malloc((word_count(s, c)) * sizeof(char *) + 1);
	if (ret == NULL)
		return (NULL);
	while (j < (word_count(s, c)))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		ret[j] = malloc (word_len(&s[i], c) * sizeof(ret) + 1);
		ft_strncpy(ret[j], &s[i], word_len(&s[i], c));
		ret[j][word_len(&s[i], c)] = '\0';
		while (s[i] != '\0' && s[i] != c)
			i++;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
