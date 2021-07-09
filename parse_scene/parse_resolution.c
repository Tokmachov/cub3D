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

#include "../libft/libft.h"
#include "../cub3d.h"
#include "../mlx/mlx.h"

static	t_bool	is_resolution_filled(t_game_params *params)
{
	if (params->window_height == NOT_SET && params->window_width == NOT_SET)
		return (false);
	return (true);
}

static	t_bool	all_digits(char *str)
{
	t_bool all_digits;

	all_digits = true;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (all_digits);
}

static	t_bool	is_correctly_formatted(char **str)
{
	if (count_words(str) != 3)
		return (false);
	if (str[0][1] != '\0')
		return (false);
	if (!all_digits(str[1]) || !all_digits(str[2]))
		return (false);
	return (true);
}

int				parse_resolution(char *str, t_game_params *params)
{
	char	**components;
	int		cur_d_w;
	int		cur_d_h;

	mlx_get_screen_size(params->mlx, &cur_d_w, &cur_d_h);
	if (is_resolution_filled(params))
		return (DUPL_CFG_ER);
	components = ft_split(str, ' ');
	if (!components)
		return (MALLOC_ER);
	if (!is_correctly_formatted(components))
	{
		free_str_array(components);
		return (RES_FMT_ERR);
	}
	params->window_width = parse_int_limited(components[1], cur_d_w);
	params->window_height = parse_int_limited(components[2], cur_d_h);
	if (params->window_width < 1 || params->window_height < 1)
		return (RSN_INVLD_VAL_ER);
	correct_resolution(params, cur_d_w, cur_d_h);
	free_str_array(components);
	return (NO_ERROR);
}
