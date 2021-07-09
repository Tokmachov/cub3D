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

static	int	compute_screen_y(int sprite_y, t_sprite *sprite)
{
	return (sprite->screen_y_origin + sprite_y);
}

void		draw_sprite_slice(int screen_x,
						int sprite_x,
						t_sprite *sprite,
						t_game_params *params)
{
	int		sprite_y;
	int		screen_y;
	int		sprite_pixel_color;
	float	corrected_sprite_dst;

	sprite_y = 0;
	corrected_sprite_dst = correct_sprite_distance(sprite, params);
	while (sprite_y < sprite->screen_size)
	{
		screen_y = compute_screen_y(sprite_y, sprite);
		sprite_pixel_color = get_sprite_pixel_color(sprite_x, sprite_y, sprite);
		if (corrected_sprite_dst < params->hit_distances[screen_x]
			&& sprite_pixel_color > 0)
			my_mlx_pixel_put(&params->buf_img,
					screen_x,
					screen_y,
					sprite_pixel_color);
		sprite_y++;
	}
}
