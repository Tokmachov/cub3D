/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_formatted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:07:49 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:28:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	width_filled_with_padding_and_arg(int padding_len, \
	t_specifiers specs)
{
	STRING	result;

	if (specs.arg_type == 's')
		result = width_filled_with_padding_and_s_arg(padding_len, specs);
	else if (specs.arg_type == 'c')
		result = width_filled_with_padding_and_c_arg(padding_len, specs);
	else if (specs.arg_type == 'd' || specs.arg_type == 'i' \
		|| specs.arg_type == 'u' || specs.arg_type == 'x' \
		|| specs.arg_type == 'X')
		result = width_filled_with_padding_and_int_arg(padding_len, specs);
	else if (specs.arg_type == 'p')
		result = width_filled_with_padding_and_p_arg(specs);
	else
		result = NULL;
	return (result);
}

STRING			arg_formatted(t_specifiers specs)
{
	STRING	result;
	int		padding_len;

	padding_len = calc_padding_len(specs);
	if (padding_len > 0)
		result = width_filled_with_padding_and_arg(padding_len, specs);
	else
	{
		if (specs.arg_type == 'p')
			result = ft_strjoin(HEX_PREFIX, specs.arg_val_str);
		else
			result = ft_strdup(specs.arg_val_str);
	}
	return (result);
}
