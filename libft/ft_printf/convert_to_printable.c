/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_printable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:03:15 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 13:35:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_printable_str	*make_printable_from_plane_str_comp(STRING comp)
{
	size_t			len;
	STRING			str;
	t_printable_str	*printable;

	len = ft_strlen(comp);
	str = ft_strdup(comp);
	if (!str)
		return (NULL);
	printable = init_printable(str, len);
	return (printable);
}

static	t_bool			is_specs(STRING comp)
{
	return (*comp == '%');
}

t_printable_str			*convert_to_printable(STRING comp, va_list args)
{
	t_printable_str	*printable;

	if (is_specs(comp))
		printable = make_printable_from_specs_comp(comp, args);
	else
		printable = make_printable_from_plane_str_comp(comp);
	return (printable);
}
