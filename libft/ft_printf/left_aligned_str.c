/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_aligned_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:44:22 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:49:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	left_aligned_str(int padding_len, STRING arg)
{
	STRING	padding;
	STRING	result;

	padding = make_filled_str(padding_len, ' ');
	result = ft_strjoin(arg, padding);
	free(padding);
	return (result);
}
