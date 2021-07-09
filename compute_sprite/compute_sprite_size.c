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

#include <math.h>
#include "../cub3d.h"

void	compute_sprite_size(t_sprite *sprite, t_game_params *params)
{
	int		sprite_size;

	sprite_size = params->distance_to_screen * SPRITE_HEIGHT / sprite->distance;
	sprite_size = sprite_size == 1 ? 0 : sprite_size;
	sprite_size = sprite_size > params->window_height ? 0 : sprite_size;
	sprite->screen_size = sprite_size;
}
