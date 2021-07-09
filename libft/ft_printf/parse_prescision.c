/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prescision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:55:44 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:22:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		prescision_len(STRING str)
{
	int	len;

	len = 0;
	while (*str && ft_isdigit(*str))
	{
		len++;
		str++;
	}
	return (len);
}

static	void	parse_place_holder_prescision(t_specifiers *specs, va_list args)
{
	int prescision;

	prescision = va_arg(args, int);
	if (prescision >= 0)
		specs->precision = prescision;
	else
		specs->precision = PRESCISION_NOT_SET;
}

int				parse_prescision(STRING str, t_specifiers *specs, va_list args)
{
	if (!*str)
		return (0);
	if (*str == '.' && ft_isdigit(*(str + 1)))
	{
		specs->precision = ft_atoi(str + 1);
		return (prescision_len(str + 1) + 1);
	}
	else if (*str == '.' && *(str + 1) == '*')
	{
		parse_place_holder_prescision(specs, args);
		return (2);
	}
	else if (*str == '.')
	{
		specs->precision = 0;
		return (1);
	}
	else
		return (0);
}
