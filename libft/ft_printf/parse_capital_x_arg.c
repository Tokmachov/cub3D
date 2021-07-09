/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capital_x_arg_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:18:00 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 18:20:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	parse_capital_x_arg(va_list args)
{
	return (ft_itoa_hex(va_arg(args, int), true));
}
