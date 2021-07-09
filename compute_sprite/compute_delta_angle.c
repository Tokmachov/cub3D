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

#include "../cub3d.h"
#include <math.h>

float	compute_delta_angle(float heading, float sprite_dir)
{
	float delta;

	delta = heading - sprite_dir;
	if (delta <= -M_PI)
		delta = 2 * M_PI + delta;
	else if (delta >= M_PI)
		delta = delta - 2 * M_PI;
	return (delta);
}
