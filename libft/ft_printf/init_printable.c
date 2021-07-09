/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 10:30:44 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:13:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printable_str	*init_printable(STRING str, size_t strlen)
{
	t_printable_str	*printable;

	printable = (t_printable_str*)malloc(1 * sizeof(t_printable_str));
	if (!printable)
		return (NULL);
	printable->str = str;
	printable->strlen = strlen;
	return (printable);
}
