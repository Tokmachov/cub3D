/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:53:17 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:57:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

STRING	parse_c_arg(va_list args)
{
	char	ch;
	STRING	arg;

	ch = (char)va_arg(args, int);
	arg = (char*)malloc(2 * sizeof(char));
	if (!arg)
		return (NULL);
	arg[0] = ch;
	arg[1] = '\0';
	return (arg);
}
