/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:46:18 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:12:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	parse_format_flag(STRING fl, t_specifiers *specs)
{
	if (*fl == '-')
	{
		specs->is_left_aligned = true;
		return (1);
	}
	else if (*fl == '0')
	{
		specs->is_zero_padded = true;
		return (1);
	}
	else
		return (0);
}

static	int	parse_l_flag(STRING fl, t_specifiers *specs)
{
	if (*fl == 'l')
	{
		if (specs->is_l == false)
			specs->is_l = true;
		else
			specs->is_ll = true;
		return (1);
	}
	else
		return (0);
}

int			parse_flag(STRING fl, t_specifiers *specs)
{
	int num_of_flags_parsed;

	num_of_flags_parsed = 0;
	if (!*fl)
		return (0);
	if ((num_of_flags_parsed = parse_format_flag(fl, specs)) != 0)
		return (num_of_flags_parsed);
	else if ((num_of_flags_parsed = parse_l_flag(fl, specs)) != 0)
		return (num_of_flags_parsed);
	else
		return (num_of_flags_parsed);
}
