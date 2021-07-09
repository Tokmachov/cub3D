/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:19:37 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 12:20:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				printed_chrs_count;
	t_printable_str	**printables;

	if (!format)
		return (ERROR);
	va_start(args, format);
	printables = make_printable_strs((char*)format, args);
	if (!printables)
		return (ERROR);
	printed_chrs_count = count_printed_chrs(printables);
	print(printables);
	free_printables(printables);
	va_end(args);
	return (printed_chrs_count);
}
