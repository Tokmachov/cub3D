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

static	int	set_texture_image(int index, t_game_params *params)
{
	char *location_dir;

	location_dir = params->textures[index].location_dir;
	params->textures[index].img_ptr = NULL;
	params->textures[index].img_ptr = mlx_xpm_file_to_image(
			params->mlx,
			location_dir,
			&params->textures[index].width,
			&params->textures[index].height);
	if (!params->textures[index].img_ptr)
		return (WRN_TXTR_LOC_ER);
	params->textures[index].addr = mlx_get_data_addr(
			params->textures[index].img_ptr,
			&params->textures[index].bpp,
			&params->textures[index].size_line,
			&params->textures[index].endian);
	params->textures[index].x_image_to_texture_ratio =
			floor(params->textures[index].width / CUBE_SIDE);
	return (NO_ERROR);
}

int			set_textures_images(t_game_params *params)
{
	int	i;
	int	result_code;

	i = 0;
	while (i < 4)
	{
		result_code = set_texture_image(i, params);
		if (is_error(result_code))
			return (result_code);
		i++;
	}
	return (NO_ERROR);
}
