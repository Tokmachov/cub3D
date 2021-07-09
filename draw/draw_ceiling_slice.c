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

void	draw_ceiling_slice(
		t_game_params *params,
		t_wall_slice wall_slice,
		int slice_x)
{
	int		slice_y;
	int		ceiling_color;
	t_image	*img;

	ceiling_color = params->ceiling_color;
	img = &params->buf_img;
	slice_y = 0;
	while (slice_y < wall_slice.origin_y)
	{
		my_mlx_pixel_put(img, slice_x, slice_y, ceiling_color);
		slice_y++;
	}
}
