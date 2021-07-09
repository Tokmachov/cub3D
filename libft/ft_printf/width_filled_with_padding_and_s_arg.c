/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_filled_with_padding_and_s_arg.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:27:59 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:31:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	width_filled_with_padding_and_s_arg(int padding_len, t_specifiers specs)
{
	STRING	result;

	if (specs.is_left_aligned)
		result = left_aligned_str(padding_len, specs.arg_val_str);
	else if (!specs.is_left_aligned && !specs.is_zero_padded)
		result = right_aligned_str(padding_len, false, specs.arg_val_str);
	else
		result = right_aligned_str(padding_len, true, specs.arg_val_str);
	return (result);
}
