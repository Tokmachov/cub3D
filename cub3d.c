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

#include "mlx.h"
#include "cub3d.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_game_params	params;
	int				result_code;

	set_game_params_to_unset_values(&params);
	if (argc == 2 || argc == 3)
	{
		result_code = validate_scene_file_extension(argv[1]);
		exit_cleanly_if_error(result_code, &params);
		result_code = init_game_params(argv[1], &params);
		exit_cleanly_if_error(result_code, &params);
	}
	else
		exit_cleanly_if_error(WRONG_ARG_NUM, &params);
	if (argc == 3)
	{
		result_code = validate_save_flag(argv[2]);
		exit_cleanly_if_error(result_code, &params);
		make_bmp_screen_shot(&params);
		exit_cleanly(&params);
	}
	result_code = open_window(&params);
	exit_cleanly_if_error(result_code, &params);
	set_hooks_mlx(&params);
	mlx_loop(params.mlx);
	return (0);
}
