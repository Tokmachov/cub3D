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

void	draw_floor_slice(
		t_game_params *params,
		t_wall_slice wall_slice,
		int slice_x)
{
	int			slice_y;
	int			floor_color;
	t_image		*img;

	floor_color = params->floor_color;
	img = &params->buf_img;
	slice_y = wall_slice.origin_y + wall_slice.corrected_height;
	while (slice_y < params->window_height)
	{
		my_mlx_pixel_put(img, slice_x, slice_y, floor_color);
		slice_y++;
	}
}
