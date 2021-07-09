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

static	int	compute_sprite_img_x(int sprite_x, t_sprite *sprite)
{
	float img_x;

	img_x = round(sprite_x
			* (sprite->img.width - 1) / (sprite->screen_size - 1));
	if (img_x >= sprite->img.width)
		img_x = sprite->img.width - 1;
	return (img_x);
}

static	int	compute_sprite_img_y(int sprite_y, t_sprite *sprite)
{
	float img_y;

	img_y = (sprite_y * (sprite->img.height - 1)) / (sprite->screen_size - 1);
	if (img_y >= sprite->img.height)
		img_y = sprite->img.height - 1;
	return (img_y);
}

int			get_sprite_pixel_color(int sprite_x, int sprite_y, t_sprite *sprite)
{
	int sprite_img_x;
	int sprite_img_y;
	int color;

	sprite_img_x = compute_sprite_img_x(sprite_x, sprite);
	sprite_img_y = compute_sprite_img_y(sprite_y, sprite);
	color = get_text_pxl_color(&sprite->img, sprite_img_x, sprite_img_y);
	return (color);
}
