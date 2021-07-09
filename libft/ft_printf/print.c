/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:02:44 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 18:36:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	print(t_printable_str **printable)
{
	while (*printable)
	{
		write(1, (*printable)->str, (*printable)->strlen);
		printable++;
	}
}
