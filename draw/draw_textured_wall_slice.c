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

static	void	correct_x_if_invalid(int *x, t_texture_data *texture)
{
	if (*x < 0)
		*x = 0;
	if (*x >= texture->width)
		*x = texture->width - 1;
}

static	void	correct_y_if_invalid(int *y, t_texture_data *texture)
{
	if (*y < 0)
		*y = 0;
	if (*y >= texture->height)
		*y = texture->height - 1;
}

void			draw_textured_wall_slice(
		t_game_params *params, t_wall_slice *wall_slice, int slice_number)
{
	float		slice_y;
	float		slice_dy;
	int			text_pxl_col;
	int			text_x;
	int			text_y;

	slice_y = wall_slice->origin_y;
	while (slice_y < (wall_slice->origin_y + wall_slice->corrected_height))
	{
		slice_dy = slice_y - wall_slice->origin_y;
		text_x = compute_texture_x(wall_slice, params);
		text_y = compute_texture_y(slice_dy, wall_slice, params);
		correct_x_if_invalid(&text_x, &params->textures[wall_slice->hit_side]);
		correct_y_if_invalid(&text_y, &params->textures[wall_slice->hit_side]);
		text_pxl_col = get_text_pxl_color(
				&params->textures[wall_slice->hit_side],
				text_x,
				text_y);
		my_mlx_pixel_put(&params->buf_img, slice_number, slice_y, text_pxl_col);
		slice_y++;
	}
}
