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

static	float	compute_sprite_heading_angle(
		t_sprite *sprite,
		t_game_params *params)
{
	float sprite_dir;
	float sprite_heading_angle;

	sprite_dir = compute_sprite_dir(sprite, params);
	sprite_heading_angle = compute_delta_angle(
			params->player.heading,
			sprite_dir);
	return (sprite_heading_angle);
}

float			correct_sprite_distance(t_sprite *sprite, t_game_params *params)
{
	float sprite_heading_angle;
	float corrected_dst;

	sprite_heading_angle = compute_sprite_heading_angle(sprite, params);
	corrected_dst = sprite->distance * cos(sprite_heading_angle);
	return (corrected_dst);
}
