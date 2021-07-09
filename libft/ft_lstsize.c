/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:20:45 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:45:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Description:
**	Counts the number of elements in a list.
**		Parameters:
**	#1.  The beginning of the list.
**		Return value:
**	Length of the list.
**		External functs:
**	None
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		size += 1;
	}
	return (size);
}
