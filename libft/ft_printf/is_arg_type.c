/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:18:51 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 17:15:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_arg_type(char c)
{
	int i;

	i = 0;
	while (ARG_TYPES[i])
	{
		if (c == ARG_TYPES[i])
			return (true);
		i++;
	}
	return (false);
}
