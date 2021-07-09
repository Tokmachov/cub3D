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

static	void	compute_first_v_hit_pos(t_position *first_hit,
									float angle,
									t_position *player_position,
									float grid_side)
{
	if (is_facing_right(angle))
		first_hit->x = floor(player_position->x / grid_side)
				* grid_side + grid_side;
	else
		first_hit->x = floor(player_position->x / grid_side)
				* grid_side - 0.0001;
	first_hit->y = player_position->y + (player_position->x - first_hit->x)
			* tan(angle);
}

void			compute_v_hit_pos(t_position *hit_position,
						float angle,
						t_game_params *params)
{
	t_position	player_pos;
	float		x_increment;
	float		y_increment;

	player_pos.x = params->player.x;
	player_pos.y = params->player.y;
	compute_first_v_hit_pos(hit_position, angle, &player_pos, CUBE_SIDE);
	x_increment = is_facing_right(angle) ? CUBE_SIDE : -CUBE_SIDE;
	y_increment = compute_y_increment(x_increment, angle);
	compute_hit_pos(hit_position, x_increment, y_increment, params);
}
