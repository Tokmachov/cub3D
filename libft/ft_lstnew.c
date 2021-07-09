/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:51:41 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 12:19:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Description:
**	Allocates (with malloc(3)) and returns a new
**	element.  The variable ’content’ is initialized
**	with the value of the parameter ’content’.  The
**	variable ’next’ is initialized to NULL.
**		Parameters:
**	#1.  The content to create the new element with.
**		Return value:
**	The new element.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(1 * sizeof(t_list));
	if (new_list)
	{
		new_list->content = content;
		new_list->next = NULL;
	}
	return (new_list);
}
