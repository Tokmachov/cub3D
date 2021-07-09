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

static	float	compute_slice_origin_y(
		t_game_params *params,
		float corrected_height)
{
	return (params->window_center.y - floor(corrected_height / 2));
}

static	float	compute_slice_height_corrected(
		int height_original,
		t_game_params *params)
{
	float	height_corrected;
	int		window_height;

	window_height = params->window_height;
	if (height_original <= window_height)
		height_corrected = height_original;
	else
		height_corrected = window_height;
	return (height_corrected);
}

static	float	compute_slice_height(
		t_wall_hit *wall_hit,
		t_game_params *params)
{
	float slice_height;
	float hit_distance;
	float distance_to_screen;

	hit_distance = wall_hit->distance;
	distance_to_screen = params->distance_to_screen;
	slice_height = round((distance_to_screen * CUBE_SIDE) / hit_distance);
	return (slice_height);
}

static float	compute_hit_offset_along_cube_edge(t_wall_hit *wall_hit)
{
	float		offset;
	t_position	*hit_pos;
	t_hit_side	hit_side;

	offset = -1;
	hit_pos = &wall_hit->position;
	hit_side = wall_hit->hit_side;
	if (wall_hit->hit_side == N)
		offset = (floor(hit_pos->x / CUBE_SIDE) * CUBE_SIDE + CUBE_SIDE)
				- hit_pos->x;
	else if (wall_hit->hit_side == S)
		offset = hit_pos->x - floor(hit_pos->x / CUBE_SIDE) * CUBE_SIDE;
	else if (hit_side == W)
		offset = hit_pos->y - floor(hit_pos->y / CUBE_SIDE) * CUBE_SIDE;
	else if (hit_side == E)
		offset = (floor(hit_pos->y / CUBE_SIDE) * CUBE_SIDE + CUBE_SIDE)
				- hit_pos->y;
	return (offset);
}

void			compute_wall_slice(t_wall_slice *wall_slice,
						int ray_num,
						t_game_params *params)
{
	float			ray_angle;
	t_wall_hit		wall_hit;
	float			original_height;
	float			corrected_height;

	ray_angle = compute_ray_angle(params, ray_num);
	compute_wall_hit(ray_angle, &wall_hit, params);
	original_height = compute_slice_height(&wall_hit, params);
	corrected_height = compute_slice_height_corrected(original_height, params);
	wall_slice->original_height = original_height;
	wall_slice->corrected_height = corrected_height;
	wall_slice->origin_x = ray_num;
	wall_slice->origin_y = compute_slice_origin_y(params, corrected_height);
	wall_slice->hit_side = wall_hit.hit_side;
	wall_slice->offset = compute_hit_offset_along_cube_edge(&wall_hit);
	wall_slice->hit_distance = wall_hit.distance;
}
