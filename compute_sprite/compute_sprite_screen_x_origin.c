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

void			compute_sprite_screen_x_origin(
		t_sprite *sprite,
		t_game_params *params)
{
	float	fov_start;
	float	sprite_dir;
	float	delta;
	float	screen_x;

	fov_start = compute_ray_angle(params, 0);
	sprite_dir = compute_sprite_dir(sprite, params);
	delta = compute_delta_angle(fov_start, sprite_dir);
	screen_x = delta / (PLAYER_FOV / params->window_width)
			- sprite->screen_size / 2;
	sprite->screen_x_origin = screen_x;
}
