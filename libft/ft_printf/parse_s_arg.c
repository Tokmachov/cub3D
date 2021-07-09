/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:58:27 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:59:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	parse_s_arg(va_list args)
{
	STRING arg;

	arg = va_arg(args, char*);
	if (!arg)
		arg = ft_strdup("(null)");
	else
		arg = ft_strdup(arg);
	return (arg);
}
