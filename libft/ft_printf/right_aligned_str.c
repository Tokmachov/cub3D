/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_aligned_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:42:10 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 18:38:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	right_aligned_str(int padding_len, t_bool is_zero_padded, STRING arg)
{
	STRING	padding;
	char	filler;
	STRING	result;

	filler = is_zero_padded ? '0' : ' ';
	padding = make_filled_str(padding_len, filler);
	result = ft_strjoin(padding, arg);
	free(padding);
	return (result);
}
