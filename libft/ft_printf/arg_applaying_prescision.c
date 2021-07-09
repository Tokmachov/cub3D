/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_applaying_prescision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:08:07 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:43:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	arg_applaying_prescision(t_specifiers specs)
{
	STRING	result_str;

	if (specs.arg_type == 'c' || specs.arg_type == '%')
		result_str = ft_strdup(specs.arg_val_str);
	else if (specs.arg_type == 's')
		result_str = arg_s_applying_prescision(specs);
	else if (specs.arg_type == 'd' || specs.arg_type == 'i')
		result_str = arg_int_applying_prescision(specs);
	else if (specs.arg_type == 'u' \
		|| specs.arg_type == 'x' || specs.arg_type == 'X' \
		|| specs.arg_type == 'p')
		result_str = arg_int_applying_prescision(specs);
	else
		result_str = NULL;
	return (result_str);
}
