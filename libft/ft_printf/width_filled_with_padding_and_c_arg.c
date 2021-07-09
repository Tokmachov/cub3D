/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_filled_with_padding_and_c_arg.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:13:48 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 17:03:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	left_aligned_null_chr_str(int padding_len)
{
	STRING	padding;
	STRING	result;

	padding = make_filled_str(padding_len, ' ');
	if (!padding)
		return (NULL);
	result = (STRING)ft_calloc(padding_len + 2, sizeof(char));
	if (!result)
	{
		free(padding);
		return (NULL);
	}
	ft_strlcpy(result + 1, padding, padding_len + 1);
	free(padding);
	return (result);
}

static	STRING	right_aligned_null_chr_str(int padding_len, \
	t_bool is_zero_padded)
{
	STRING	padding;
	char	filler;
	STRING	result;

	filler = is_zero_padded ? '0' : ' ';
	padding = make_filled_str(padding_len, filler);
	if (!padding)
		return (NULL);
	result = (STRING)ft_calloc(padding_len + 2, sizeof(char));
	if (!result)
	{
		free(padding);
		return (NULL);
	}
	ft_strlcpy(result, padding, padding_len + 2);
	free(padding);
	return (result);
}

static	STRING	null_c_arg_applaying_width_and_alignment(int padding_len, \
	t_specifiers specs)
{
	STRING	result;

	if (specs.is_left_aligned)
		result = left_aligned_null_chr_str(padding_len);
	else
		result = right_aligned_null_chr_str(padding_len, specs.is_zero_padded);
	return (result);
}

STRING			width_filled_with_padding_and_c_arg(int padding_len, \
	t_specifiers specs)
{
	STRING result;

	if (*specs.arg_val_str != '\0')
		result = width_filled_with_padding_and_s_arg(padding_len, specs);
	else
		result = null_c_arg_applaying_width_and_alignment(padding_len, specs);
	return (result);
}
