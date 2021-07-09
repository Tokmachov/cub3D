/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:48:50 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:07:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

static	t_specifiers	*init_specs(void)
{
	t_specifiers	*specs;

	specs = (t_specifiers*)malloc(1 * sizeof(t_specifiers));
	if (!specs)
		return (NULL);
	specs->is_left_aligned = false;
	specs->is_zero_padded = false;
	specs->precision = PRESCISION_NOT_SET;
	specs->width = 0;
	specs->arg_type = '\0';
	specs->arg_val_str = NULL;
	specs->is_l = false;
	specs->is_ll = false;
	return (specs);
}

t_specifiers			*parse_specs(STRING comp, va_list args)
{
	t_specifiers	*specs;
	t_specifiers	**specs_ptr;

	specs = init_specs();
	if (!specs)
		return (NULL);
	specs_ptr = &specs;
	comp++;
	while (*comp)
	{
		comp += parse_flag(comp, specs);
		comp += parse_width(comp, specs, args);
		comp += parse_prescision(comp, specs, args);
		comp += parse_arg(comp, specs_ptr, args);
	}
	return (specs);
}
