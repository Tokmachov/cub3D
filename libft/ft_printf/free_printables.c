/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_printables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:59:14 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:55:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_printables(t_printable_str **printable)
{
	int	i;

	i = 0;
	while (printable[i])
	{
		free((printable[i])->str);
		free(printable[i]);
		i++;
	}
	free(printable);
}
