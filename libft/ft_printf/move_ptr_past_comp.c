/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ptr_past_comp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:37:02 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 13:01:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	move_ptr_past_specs(STRING format)
{
	format++;
	while (*format && (is_flag(*format) || ft_isdigit(*format)))
		format++;
	if (*format)
		return (++format);
	else
		return (format);
}

static	STRING	move_ptr_past_plane_str(STRING format)
{
	format++;
	while (*format != '\0' && *format != '%')
		format++;
	return (format);
}

STRING			move_ptr_past_comp(char *ptr)
{
	if (*ptr == '%')
		ptr = move_ptr_past_specs(ptr);
	else
		ptr = move_ptr_past_plane_str(ptr);
	return (ptr);
}
