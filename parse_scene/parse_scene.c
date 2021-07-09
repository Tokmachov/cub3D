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

#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../cub3d.h"

int	parse_scene(char *scene_file_path, t_game_params *params)
{
	int fd;
	int	res_code;

	fd = open(scene_file_path, O_RDONLY);
	if (fd < 0)
		return (FAIL_OPN_FILE_ER);
	if (is_error((res_code = parse_config(fd, params))))
		return (res_code);
	if (is_error((res_code = parse_map(fd, params))))
		return (res_code);
	if (is_error((res_code = validate_players_count_on_map(params))))
		return (res_code);
	if (is_error((res_code = parse_player(params))))
		return (res_code);
	if (is_error((res_code = parse_sprites(params))))
		return (res_code);
	set_sprites_img_values_null(params);
	return (res_code);
}
