/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_padding_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:30:50 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:52:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define HEX_PREFIX_LEN 2

int	calc_padding_len(t_specifiers specs)
{
	if (specs.arg_type == 'c')
		return (specs.width - 1);
	else if (specs.arg_type == 'p')
		return (specs.width - ft_strlen(specs.arg_val_str) - HEX_PREFIX_LEN);
	else
		return (specs.width - ft_strlen(specs.arg_val_str));
}
