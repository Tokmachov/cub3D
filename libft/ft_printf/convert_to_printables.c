/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_printables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:06:50 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 13:13:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	count_strs(STRING *strs)
{
	size_t len;

	len = 0;
	while (*strs)
	{
		len++;
		strs++;
	}
	return (len);
}

t_printable_str	**convert_to_printables(STRING *comps, va_list args)
{
	size_t			comps_count;
	t_printable_str	**printables;
	int				i;

	comps_count = count_strs(comps);
	printables = \
		(t_printable_str**)malloc((comps_count + 1) * sizeof(t_printable_str*));
	if (!printables)
		return (NULL);
	printables[comps_count] = NULL;
	i = 0;
	while (comps[i])
	{
		printables[i] = convert_to_printable(comps[i], args);
		if (!printables[i])
		{
			free_printables(printables);
			return (NULL);
		}
		i++;
	}
	return (printables);
}
