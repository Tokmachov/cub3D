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

int		get_text_pxl_color(t_texture_data *texture_data, int x, int y)
{
	return (*(unsigned int*)(texture_data->addr
	+ y * texture_data->size_line + x * (texture_data->bpp / 8)));
}

float	compute_texture_x(t_wall_slice *slice, t_game_params *params)
{
	float cube_side_offset;
	float x_image_texture_ratio;

	cube_side_offset = slice->offset;
	x_image_texture_ratio =
			params->textures[slice->hit_side].x_image_to_texture_ratio;
	return (floor(cube_side_offset * x_image_texture_ratio));
}

float	compute_texture_y(
		float slice_dy,
		t_wall_slice *slice,
		t_game_params *params)
{
	float texture_height;

	texture_height = params->textures[slice->hit_side].height;
	slice_dy = (slice->original_height - slice->corrected_height) / 2
			+ slice_dy;
	return (floor(slice_dy * texture_height / slice->original_height));
}
