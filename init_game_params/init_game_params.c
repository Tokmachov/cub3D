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

int		init_game_params(char *scene_file_path, t_game_params *params)
{
	int result_code;

	if (is_error((result_code = init_mlx(params))))
		return (result_code);
	if (is_error((result_code = parse_scene(scene_file_path, params))))
		return (result_code);
	if (is_error((result_code = set_textures_images(params))))
		return (result_code);
	if (is_error((result_code = set_sprites_images(params))))
		return (result_code);
	if (is_error((result_code = set_hit_distances_arr(params))))
		return (result_code);
	if (is_error((result_code = set_buffer_image(params))))
		return (result_code);
	set_mlx_window_center(params);
	set_distance_to_projection_screen(params);
	return (result_code);
}
