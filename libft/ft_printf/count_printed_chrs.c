/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_printed_chrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:00:32 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:54:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_printed_chrs(t_printable_str **printable)
{
	size_t count;

	count = 0;
	while (*printable)
	{
		count += (*printable)->strlen;
		printable++;
	}
	return (count);
}
