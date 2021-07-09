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

static	t_bool	is_visible_on_screen(int screen_x, t_game_params *params)
{
	return (screen_x >= 0 && screen_x < params->window_width);
}

static	int		compute_screen_x(int sprite_x, t_sprite *sprite)
{
	return (sprite->screen_x_origin + sprite_x);
}

void			draw_sprite(t_sprite *sprite, t_game_params *params)
{
	int	sprite_x;
	int	screen_x;

	sprite_x = 0;
	while (sprite_x < sprite->screen_size)
	{
		screen_x = compute_screen_x(sprite_x, sprite);
		if (is_visible_on_screen(screen_x, params))
			draw_sprite_slice(screen_x, sprite_x, sprite, params);
		sprite_x++;
	}
}
