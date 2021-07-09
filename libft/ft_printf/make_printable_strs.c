/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_printable_strs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:56:42 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 12:22:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_printable_str	**make_printable_strs(STRING format, va_list args)
{
	STRING			*comps;
	t_printable_str	**printables;

	comps = split_to_comps(format);
	if (!comps)
		return (NULL);
	printables = convert_to_printables(comps, args);
	free_comps(comps);
	return (printables);
}
