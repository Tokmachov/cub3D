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

float	compute_sprite_dir(t_sprite *sprite, t_game_params *params)
{
	float sprite_dir;

	sprite_dir = atan2(
			params->player.y - sprite->y, sprite->x - params->player.x);
	sprite_dir = sprite_dir >= 0 ? sprite_dir : 2 * M_PI + sprite_dir;
	return (sprite_dir);
}
