/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:36:02 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 12:14:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Description:
**	Returns the last element of the list.
**		Parameters:
**	#1.  The beginning of the list.
**		Return value:
**	Last element of the list.
**		External functs:
**	None
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *current;

	if (lst == NULL)
		return (lst);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
