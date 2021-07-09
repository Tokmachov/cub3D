/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:51:32 by mac               #+#    #+#             */
/*   Updated: 2020/05/29 12:04:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Description:
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element.  Creates a new
** list resulting of the successive applications of
** the function ’f’.  The ’del’ function is used to
** delete the content of an element if needed.
**	Parameters:
** #1.  The adress of a pointer to an element.
** #2.  The adress of the function used to iterate on
**      the list.
** #3.  The adress of the function used to delete the
**		content of an element if needed.
**	Return value:
**	The new list.  NULL if the allocation fails.
** External functs:
**	malloc, free
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	void	*new_content;
	t_list	*new_element;
	t_list	*current;

	if (f == NULL || del == NULL)
		return (NULL);
	new_head = NULL;
	current = lst;
	while (current != NULL)
	{
		new_content = f(current->content);
		new_element = ft_lstnew(new_content);
		if (new_element == NULL)
		{
			ft_lstclear(&new_head, del);
			return (new_head);
		}
		ft_lstadd_back(&new_head, new_element);
		current = current->next;
	}
	return (new_head);
}
