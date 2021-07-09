/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:45:54 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 12:54:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	specs_strlen(char *ptr)
{
	size_t len;

	len = 1;
	ptr++;
	while (*ptr && (is_flag(*ptr) || ft_isdigit(*ptr)))
	{
		len++;
		ptr++;
	}
	if (*ptr)
		len++;
	return (len);
}

static	size_t	plane_strlen(char *ptr)
{
	size_t len;

	len = 0;
	while (*ptr && *ptr != '%')
	{
		len++;
		ptr++;
	}
	return (len);
}

static	size_t	complen(STRING format)
{
	size_t len;

	if (*format == '%')
		len = specs_strlen(format);
	else
		len = plane_strlen(format);
	return (len);
}

STRING			get_comp(STRING format)
{
	size_t	len;

	len = complen(format);
	return (ft_substr(format, 0, len));
}
