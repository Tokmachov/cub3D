/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_comps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:52:36 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 12:49:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_comps(STRING format)
{
	int	comp_count;

	comp_count = 0;
	while (*format)
	{
		format = move_ptr_past_comp(format);
		comp_count++;
	}
	return (comp_count);
}

STRING			*split_to_comps(STRING format)
{
	int		count;
	STRING	*comps;
	int		i;

	count = count_comps(format);
	comps = (STRING*)malloc((count + 1) * sizeof(STRING));
	if (!comps)
		return (NULL);
	comps[count] = NULL;
	i = 0;
	while (*format)
	{
		comps[i] = get_comp(format);
		if (comps[i] == NULL)
		{
			free_comps(comps);
			return (NULL);
		}
		format = move_ptr_past_comp(format);
		i += 1;
	}
	return (comps);
}
