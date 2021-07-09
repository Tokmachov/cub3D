/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:52:44 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:20:36 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Description:
**	Takes as a parameter an element and frees the
**	memory of the element’s content using the function
**	’del’ given as a parameter and free the element.
**	The memory of ’next’ must not be freed.
**		Parameters:
**	#1.  The element to free.
**	#2.  The address of the function used to delete the
**	content.
**		Return value:
**	None
**		External functs:
**	free
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}
