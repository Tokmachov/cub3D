/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:52:26 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:17:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		numlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	void	parse_place_holder_width(t_specifiers *specs, va_list args)
{
	int	width;

	width = va_arg(args, int);
	if (width >= 0)
		specs->width = width;
	else
	{
		specs->is_left_aligned = true;
		specs->width = -width;
	}
}

int				parse_width(STRING str, t_specifiers *specs, va_list args)
{
	int	numparsed;

	if (!*str)
		return (0);
	if (ft_isdigit(*str) && !is_flag(*str))
	{
		numparsed = ft_atoi(str);
		specs->width = numparsed;
		return (numlen(numparsed));
	}
	else if (*str == '*')
	{
		parse_place_holder_width(specs, args);
		return (1);
	}
	else
		return (0);
}
