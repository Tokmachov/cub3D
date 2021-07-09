/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_filled_with_padding_and_int_arg.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:25:21 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 16:05:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	neg_int_right_aligned_str(int padding_len, \
	t_bool is_zero_padded, STRING arg)
{
	STRING	no_minus_str;
	STRING	result;
	STRING	minus_sign;

	if (is_zero_padded)
	{
		no_minus_str = right_aligned_str(padding_len, is_zero_padded, arg + 1);
		minus_sign = ft_strdup("-");
		result = ft_strjoin(minus_sign, no_minus_str);
		free(no_minus_str);
		free(minus_sign);
	}
	else
		result = right_aligned_str(padding_len, is_zero_padded, arg);
	return (result);
}

STRING			width_filled_with_padding_and_int_arg(int padding_len, \
	t_specifiers specs)
{
	STRING	result;

	if (specs.is_left_aligned)
		result = left_aligned_str(padding_len, specs.arg_val_str);
	else
	{
		if (specs.precision == PRESCISION_NOT_SET)
			if (*specs.arg_val_str == '-')
				result = neg_int_right_aligned_str(padding_len, \
					specs.is_zero_padded, specs.arg_val_str);
			else
				result = right_aligned_str(padding_len, \
					specs.is_zero_padded, specs.arg_val_str);
		else
			result = right_aligned_str(padding_len, false, specs.arg_val_str);
	}
	return (result);
}
