/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_comps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:04:07 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 12:58:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	free_comps(STRING *comps)
{
	int i;

	i = 0;
	while (comps[i])
	{
		free(comps[i]);
		i++;
	}
	free(comps);
}
