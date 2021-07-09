/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_specs_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 17:02:13 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:40:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	convert_specs_to_str(t_specifiers specs)
{
	STRING	str_with_prescision;
	STRING	result_str;

	if (!specs.arg_val_str && specs.arg_type == '\0')
		return (ft_strdup(""));
	str_with_prescision = arg_applaying_prescision(specs);
	if (!str_with_prescision)
		return (NULL);
	specs.arg_val_str = str_with_prescision;
	result_str = arg_formatted(specs);
	free(str_with_prescision);
	return (result_str);
}
