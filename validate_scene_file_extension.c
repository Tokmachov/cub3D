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
#include "libft/libft.h"

static	t_bool	is_scene_file_extension_valid(char *file_path)
{
	char *point_ptr;

	point_ptr = ft_strrchr(file_path, '.');
	if (point_ptr && (ft_strncmp(".cub", point_ptr, 5)) == 0)
		return (true);
	else
		return (false);
}

int				validate_scene_file_extension(char *file_path)
{
	if (is_scene_file_extension_valid(file_path))
		return (NO_ERROR);
	else
		return (WRN_FILE_EXT);
}
