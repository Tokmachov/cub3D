/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:42:15 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:29:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Description:
**	Iterates the list ’lst’ and applies the function
**	’f’ to the content of each element.
**		Parameters:
**	#1.	The adress of a pointer to an element.
**	#2.	The adress of the function used to iterate on
**		the list.
**		Return value:
**	None
**		External functs:
**	None
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *current;

	current = lst;
	if (lst == NULL)
		return ;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
