/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p_applying_prescision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:26:14 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:18:18 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	arg_p_applying_prescision(t_specifiers specs)
{
	int		zeros_num;
	int		prescision;
	STRING	result;
	STRING	zeros;

	if (specs.precision == PRESCISION_NOT_SET)
		prescision = 0;
	else
		prescision = specs.precision;
	zeros_num = prescision - ft_strlen(specs.arg_val_str);
	if (zeros_num > 0)
	{
		zeros = make_filled_str(zeros_num, '0');
		result = ft_strjoin(zeros, specs.arg_val_str);
		free(zeros);
	}
	else
		result = ft_strdup(specs.arg_val_str);
	return (result);
}
