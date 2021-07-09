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
#include <stdlib.h>
#include "mlx.h"
#include <unistd.h>

static	void	free_sprites_images(t_game_params *params)
{
	if (params->sprites)
	{
		if ((params->mlx) && (params->sprites[0].img.img_ptr))
			mlx_destroy_image(params->mlx, params->sprites[0].img.img_ptr);
		free(params->sprites[0].img.location_dir);
		params->sprites[0].img.img_ptr = NULL;
		params->sprites[0].img.location_dir = NULL;
	}
	free(params->sprites);
}

static	void	free_textures_images(t_game_params *params)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(params->textures[i].location_dir);
		if ((params->mlx) && (params->textures[i].img_ptr))
			mlx_destroy_image(params->mlx, params->textures[i].img_ptr);
		params->textures[i].location_dir = NULL;
		params->textures[i].img_ptr = NULL;
		i++;
	}
}

void			free_game_params(t_game_params *params)
{
	if ((params->mlx) && (params->buf_img.img))
	{
		mlx_destroy_image(params->mlx, params->buf_img.img);
		params->buf_img.img = NULL;
	}
	if ((params->window) && (params->mlx))
	{
		mlx_destroy_window(params->mlx, params->window);
		params->window = NULL;
	}
	free_textures_images(params);
	free(params->sprite_texture_dir);
	free_sprites_images(params);
	free_str_array(params->map);
	free(params->hit_distances);
}
