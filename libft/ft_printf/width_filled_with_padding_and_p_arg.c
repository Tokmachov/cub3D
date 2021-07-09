/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_filled_with_padding_and_p_arg.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:37:02 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 17:04:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	make_right_aligned_str(int padding_len, t_specifiers specs)
{
	STRING	no_prefix_resut;
	STRING	result;
	STRING	prefixed_hex;

	if (specs.is_zero_padded == true \
		&& specs.precision == PRESCISION_NOT_SET)
	{
		no_prefix_resut = right_aligned_str(padding_len, \
			true, specs.arg_val_str);
		result = ft_strjoin(HEX_PREFIX, no_prefix_resut);
		free(no_prefix_resut);
	}
	else
	{
		prefixed_hex = ft_strjoin(HEX_PREFIX, specs.arg_val_str);
		result = right_aligned_str(padding_len, false, prefixed_hex);
		free(prefixed_hex);
	}
	return (result);
}

static	STRING	make_left_aligned_str(int padding_len, STRING arg)
{
	STRING no_prefix_result;
	STRING result;

	no_prefix_result = left_aligned_str(padding_len, arg);
	result = ft_strjoin(HEX_PREFIX, no_prefix_result);
	free(no_prefix_result);
	return (result);
}

STRING			width_filled_with_padding_and_p_arg(t_specifiers specs)
{
	int		padding_len;
	STRING	result;

	padding_len = calc_padding_len(specs);
	if (specs.is_left_aligned)
		result = make_left_aligned_str(padding_len, specs.arg_val_str);
	else
		result = make_right_aligned_str(padding_len, specs);
	return (result);
}
