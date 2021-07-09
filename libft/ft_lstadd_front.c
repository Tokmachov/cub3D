/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 15:45:55 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 11:59:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters:
**	#1.  The address of a pointer to the first link of
**	a list.
**	#2.  The address of a pointer to the element to be
**	added to the list.
** Return value:
**	None
** External functs:
**	None
** Description:
**	Adds the element ’new’ at the beginning of the
**	list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
