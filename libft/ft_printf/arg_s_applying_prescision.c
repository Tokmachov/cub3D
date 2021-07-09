/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s_applying_prescision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:11:06 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:09:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	strlen_to_cpy(t_specifiers specs)
{
	int	arg_len;

	arg_len = ft_strlen(specs.arg_val_str);
	if (specs.precision == PRESCISION_NOT_SET)
		return (arg_len);
	else
		return (ft_minints(arg_len, specs.precision));
}

STRING		arg_s_applying_prescision(t_specifiers specs)
{
	return (ft_substr(specs.arg_val_str, 0, strlen_to_cpy(specs)));
}
