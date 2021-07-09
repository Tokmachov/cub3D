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

int	parse_no_texture_dir(char *str, t_game_params *params)
{
	char *texture;

	str++;
	str++;
	if (params->textures[N].location_dir != NULL)
		return (DUPL_CFG_ER);
	texture = parse_texture_dir(str);
	if (texture)
	{
		params->textures[N].location_dir = texture;
		return (NO_ERROR);
	}
	else
		return (TEXTURE_ER);
}

int	parse_so_texture_dir(char *str, t_game_params *params)
{
	char *texture;

	str++;
	str++;
	if (params->textures[S].location_dir != NULL)
		return (DUPL_CFG_ER);
	texture = parse_texture_dir(str);
	if (texture)
	{
		params->textures[S].location_dir = texture;
		return (NO_ERROR);
	}
	else
		return (TEXTURE_ER);
}

int	parse_we_texture_dir(char *str, t_game_params *params)
{
	char *texture;

	str++;
	str++;
	if (params->textures[W].location_dir != NULL)
		return (DUPL_CFG_ER);
	texture = parse_texture_dir(str);
	if (texture)
	{
		params->textures[W].location_dir = texture;
		return (NO_ERROR);
	}
	else
		return (TEXTURE_ER);
}

int	parse_ea_texture_dir(char *str, t_game_params *params)
{
	char *texture_dir;

	str++;
	str++;
	if (params->textures[E].location_dir != NULL)
		return (DUPL_CFG_ER);
	texture_dir = parse_texture_dir(str);
	if (texture_dir)
	{
		params->textures[E].location_dir = texture_dir;
		return (NO_ERROR);
	}
	else
		return (TEXTURE_ER);
}

int	parse_sprite_texture_dir(char *str, t_game_params *params)
{
	char *texture;

	str++;
	if (params->sprite_texture_dir != NULL)
		return (DUPL_CFG_ER);
	texture = parse_texture_dir(str);
	if (texture)
	{
		params->sprite_texture_dir = texture;
		return (NO_ERROR);
	}
	else
		return (TEXTURE_ER);
}
