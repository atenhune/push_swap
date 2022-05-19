/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:05:16 by antti             #+#    #+#             */
/*   Updated: 2021/11/22 12:37:47 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list *)malloc (sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = NULL;
		return (ret);
	}
	ret->content = (void *)malloc(content_size);
	ret->content = ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
