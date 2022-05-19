/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:43:17 by antti             #+#    #+#             */
/*   Updated: 2021/11/11 15:03:45 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;
	char	*ret;

	ret = (char *) haystack;
	i = 0;
	if (needle[i] == '\0')
	{
		return (ret);
	}
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] != '\0' && haystack[i + k] == needle[k])
		{
			if (needle [k + 1] == '\0')
				return (&ret[i]);
			k++;
		}
		i++;
	}
	return (0);
}
