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

#include "init_game_params.h"

static	int	get_sprite_texture(t_texture_data *texture, t_game_params *params)
{
	char *dir;

	dir = params->sprite_texture_dir;
	texture->img_ptr = NULL;
	texture->img_ptr = mlx_xpm_file_to_image(
			params->mlx,
			dir,
			&texture->width,
			&texture->height);
	if (!texture->img_ptr)
		return (WRN_TXTR_LOC_ER);
	texture->addr = mlx_get_data_addr(
			texture->img_ptr,
			&texture->bpp,
			&texture->size_line,
			&texture->endian);
	texture->x_image_to_texture_ratio = floor(texture->width / CUBE_SIDE);
	texture->location_dir = NULL;
	return (NO_ERROR);
}

int			set_sprites_images(t_game_params *params)
{
	int				i;
	t_texture_data	texture;
	int				result_code;

	result_code = get_sprite_texture(&texture, params);
	if (result_code != NO_ERROR)
		return (result_code);
	i = 0;
	while (i < params->sprites_count)
	{
		params->sprites[i].img = texture;
		i++;
	}
	return (result_code);
}
