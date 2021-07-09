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

static	void	compute_first_h_hit_pos(t_position *first_hit,
									float angle,
									t_position *player_position)
{
	if (is_facing_up(angle))
		first_hit->y = floor(player_position->y / CUBE_SIDE)
				* CUBE_SIDE - 0.0001;
	else
		first_hit->y = floor(player_position->y / CUBE_SIDE)
				* CUBE_SIDE + CUBE_SIDE;
	first_hit->x = player_position->x + (player_position->y
			- first_hit->y) / tan(angle);
}

void			compute_h_hit_pos(t_position *hit_position,
					float angle,
					t_game_params *params)
{
	float		x_increment;
	float		y_increment;
	t_position	player_pos;

	player_pos.x = params->player.x;
	player_pos.y = params->player.y;
	compute_first_h_hit_pos(hit_position, angle, &player_pos);
	y_increment = is_facing_up(angle) ? -1 * CUBE_SIDE : CUBE_SIDE;
	x_increment = compute_x_increment(y_increment, angle);
	compute_hit_pos(hit_position, x_increment, y_increment, params);
}
