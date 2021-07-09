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

#include "cub3d.h"
#include <math.h>

static	float	compute_distance(t_position *p1, t_position *p2)
{
	float dx;
	float dy;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return (sqrt(dx * dx + dy * dy));
}

static	float	correct_distance(float distance,
							float angle,
							t_game_params *params)
{
	return (distance * cos(fabs(params->player.heading - angle)));
}

static	void	compute_h_wall_hit(float ray_angle,
							t_wall_hit *wall_hit,
							t_game_params *params)
{
	t_position	hit_pos;
	t_position	player_pos;
	float		hit_distance;

	compute_h_hit_pos(&hit_pos, ray_angle, params);
	player_pos.x = params->player.x;
	player_pos.y = params->player.y;
	hit_distance = compute_distance(&hit_pos, &player_pos);
	wall_hit->distance = correct_distance(hit_distance, ray_angle, params);
	wall_hit->position = hit_pos;
	wall_hit->hit_side = is_facing_up(ray_angle) ? S : N;
}

static	void	compute_v_wall_hit(float ray_angle,
							t_wall_hit *wall_hit,
							t_game_params *params)
{
	t_position	hit_pos;
	t_position	player_pos;
	float		hit_distance;

	compute_v_hit_pos(&hit_pos, ray_angle, params);
	player_pos.x = params->player.x;
	player_pos.y = params->player.y;
	hit_distance = compute_distance(&hit_pos, &player_pos);
	wall_hit->distance = correct_distance(hit_distance, ray_angle, params);
	wall_hit->position = hit_pos;
	wall_hit->hit_side = is_facing_right(ray_angle) ? W : E;
}

void			compute_wall_hit(float ray_angle,
					t_wall_hit *wall_hit,
					t_game_params *params)
{
	t_wall_hit h_wall_hit;
	t_wall_hit v_wall_hit;

	compute_h_wall_hit(ray_angle, &h_wall_hit, params);
	compute_v_wall_hit(ray_angle, &v_wall_hit, params);
	if (v_wall_hit.distance <= h_wall_hit.distance)
		*wall_hit = v_wall_hit;
	else
		*wall_hit = h_wall_hit;
}
