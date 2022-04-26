/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:26:28 by antti             #+#    #+#             */
/*   Updated: 2021/11/20 15:36:25 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*node;

	node = *alst;
	while (node != NULL)
	{
		temp = node->next;
		del(node->content, node->content_size);
		free(node);
		node = temp;
	}
	*alst = NULL;
}
