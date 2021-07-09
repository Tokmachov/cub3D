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

static	void	set_player_to_unset_values(t_game_params *params)
{
	params->player.x = NOT_SET;
	params->player.y = NOT_SET;
	params->player.heading = NOT_SET;
}

static	void	set_textures_images_to_unset_values(t_game_params *params)
{
	params->textures[N].location_dir = NULL;
	params->textures[E].location_dir = NULL;
	params->textures[S].location_dir = NULL;
	params->textures[W].location_dir = NULL;
	params->textures[N].addr = NULL;
	params->textures[E].addr = NULL;
	params->textures[S].addr = NULL;
	params->textures[W].addr = NULL;
	params->textures[N].img_ptr = NULL;
	params->textures[E].img_ptr = NULL;
	params->textures[S].img_ptr = NULL;
	params->textures[W].img_ptr = NULL;
}

static	void	set_config_to_unset_values(t_game_params *params)
{
	params->window_width = NOT_SET;
	params->window_height = NOT_SET;
	params->ceiling_color = NOT_SET;
	params->floor_color = NOT_SET;
	set_textures_images_to_unset_values(params);
	params->sprite_texture_dir = NULL;
	params->sprites = NULL;
}

void			set_game_params_to_unset_values(t_game_params *params)
{
	set_config_to_unset_values(params);
	set_player_to_unset_values(params);
	params->map = NULL;
	params->buf_img.addr = NULL;
	params->buf_img.img = NULL;
	params->hit_distances = NULL;
	params->mlx = NULL;
	params->window = NULL;
}
