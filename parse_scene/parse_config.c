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
#include "../libft/libft.h"
#include <stdlib.h>

static	t_id_and_func	*make_ids_and_parse_funcs(void)
{
	t_id_and_func *ids_and_parse_funcs;

	ids_and_parse_funcs = (t_id_and_func *)malloc(8 * sizeof(t_id_and_func));
	if (!ids_and_parse_funcs)
		return (NULL);
	ids_and_parse_funcs[0] = (t_id_and_func){"R ", parse_resolution };
	ids_and_parse_funcs[1] = (t_id_and_func){"F ", parse_floor_color };
	ids_and_parse_funcs[2] = (t_id_and_func){"C ", parse_ceiling_color };
	ids_and_parse_funcs[3] = (t_id_and_func){"NO", parse_no_texture_dir };
	ids_and_parse_funcs[4] = (t_id_and_func){"SO", parse_so_texture_dir };
	ids_and_parse_funcs[5] = (t_id_and_func){"WE", parse_we_texture_dir };
	ids_and_parse_funcs[6] = (t_id_and_func){"EA", parse_ea_texture_dir };
	ids_and_parse_funcs[7] = (t_id_and_func){"S ", parse_sprite_texture_dir };
	return (ids_and_parse_funcs);
}

static	t_parse_func	make_parse_func(char *id)
{
	int				i;
	int				funcs_qty;
	t_id_and_func	*ids_and_funcs;

	if (!(ids_and_funcs = make_ids_and_parse_funcs()))
		return (NULL);
	i = 0;
	funcs_qty = 8;
	while (i < funcs_qty)
	{
		if (ft_strncmp(id, ids_and_funcs[i].id, 2) == 0)
		{
			free(ids_and_funcs);
			return (ids_and_funcs[i].f);
		}
		i++;
	}
	free(ids_and_funcs);
	return (NULL);
}

static	t_bool			is_parsing_complete(t_game_params *params)
{
	if (params->window_height == NOT_SET)
		return (false);
	if (params->window_width == NOT_SET)
		return (false);
	if (params->floor_color == NOT_SET)
		return (false);
	if (params->ceiling_color == NOT_SET)
		return (false);
	if (params->textures[N].location_dir == NULL)
		return (false);
	if (params->textures[W].location_dir == NULL)
		return (false);
	if (params->textures[E].location_dir == NULL)
		return (false);
	if (params->textures[S].location_dir == NULL)
		return (false);
	if (params->sprite_texture_dir == NULL)
		return (false);
	return (true);
}

static	int				parse_config_line(char *config_start,
								t_game_params *params)
{
	t_parse_func	func;
	int				error_code;

	error_code = NO_ERROR;
	if ((func = make_parse_func(config_start)))
		error_code = func(config_start, params);
	else
		error_code = UNKNOWN_CFG_ID_ER;
	return (error_code);
}

int						parse_config(int fd, t_game_params *params)
{
	char	*read_line;
	int		error_code;
	int		gnl_result;

	error_code = NO_ERROR;
	while ((gnl_result = get_next_line(fd, &read_line)) > 0)
	{
		if (*read_line)
			error_code = parse_config_line(read_line, params);
		free(read_line);
		read_line = NULL;
		if (is_parsing_complete(params) || is_error(error_code))
			break ;
	}
	if (gnl_result == 0)
		error_code = PARAMS_MISSED_ER;
	if (gnl_result < 0)
		error_code = GNL_ER;
	free(read_line);
	return (error_code);
}
