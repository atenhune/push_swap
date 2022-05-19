/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:19:02 by antti             #+#    #+#             */
/*   Updated: 2021/11/23 16:04:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*prev;
	t_list	*next;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = f(lst);
	head = (t_list *)malloc (sizeof(t_list));
	head->content = (void *)malloc(temp->content_size);
	ft_memcpy(head->content, temp->content, temp->content_size);
	head->content_size = temp->content_size;
	lst = lst->next;
	prev = head;
	while (lst != NULL)
	{
		temp = f(lst);
		next = ft_lstnew(temp->content, temp->content_size);
		prev->next = next;
		prev = next;
		lst = lst->next;
	}
	return (head);
}
