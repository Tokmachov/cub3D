/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:23 by sjolynn           #+#    #+#             */
/*   Updated: 2020/08/25 16:41:18 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "cub3d.h"

void	reduce_to_one_circle(float *angle)
{
	if (*angle > 2 * M_PI)
		*angle = fmod(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = 2 * M_PI + fmod(*angle, 2 * M_PI);
}

void	increment_angle(float *angle, float increment)
{
	*angle = *angle + increment;
	reduce_to_one_circle(angle);
}

void	assert(t_bool condition, char *message)
{
	if (!condition)
	{
		ft_printf("%s\n", message);
		exit(0);
	}
}

char	*skip_spaces(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (str);
}
