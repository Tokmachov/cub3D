/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:44:37 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:26:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Description:
**	Adds the element ’new’ at the end of the list.
**		Parameters:
**	#1.	The address of a pointer to the first link of
**		a list.
**	#2.	The address of a pointer to the element to be
**		added to the list.
**		Return value:
**	None
**		External functs:
**	None
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
