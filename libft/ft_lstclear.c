/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:06:35 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:13:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Description:
**	Deletes and frees the given element and every
**	successor of that element, using the function ’del’
**	and free(3).
**	Finally, the pointer to the list must be set to
**	NULL.
**		Parameters:
**	#1.  The adress of a pointer to an element.
**	#2.  The adress of the function used to delete the
**	content of the element.
**		Return value:
**	None
**		External functs:
**	free
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (lst == NULL || *lst == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		if (del)
			del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
