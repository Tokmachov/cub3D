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

static	int		check_if_separated(char **map)
{
	while (*map && **map == '\0')
		map++;
	while (*map)
	{
		if (**map == '\0')
			return (INVLD_MAP_ER);
		map++;
	}
	return (NO_ERROR);
}

static	size_t	calc_spaces_to_add(char *line, int longest_line)
{
	size_t len;

	len = ft_strlen(line);
	return (longest_line - len);
}

static	char	*add_spaces_to_back_of_line(char *line, int number_of_spaces)
{
	char	*new_line;
	char	*spaces_padding;

	spaces_padding = (char*)ft_calloc(number_of_spaces + 1, sizeof(char));
	if (!spaces_padding)
		return (NULL);
	ft_memset(spaces_padding, ' ', number_of_spaces);
	new_line = ft_strjoin(line, spaces_padding);
	free(spaces_padding);
	return (new_line);
}

static	int		make_map_lines_equal(char **map)
{
	int		longest_line_len;
	int		i;
	char	*new_line;
	int		spaces_num;

	longest_line_len = find_longest_line_len(map);
	i = 0;
	while (map[i])
	{
		spaces_num = calc_spaces_to_add(map[i], longest_line_len);
		new_line = add_spaces_to_back_of_line(map[i], spaces_num);
		if (!new_line)
			return (MALLOC_ER);
		free(map[i]);
		map[i] = new_line;
		i++;
	}
	return (NO_ERROR);
}

int				parse_map(int fd, t_game_params *params)
{
	char	**map;
	int		result_code;

	if (!(map = get_map(fd)))
		return (FAIL_PARS_MAP_ER);
	if ((is_error((result_code = check_if_separated(map))))
		|| is_error((result_code = make_map_lines_equal(map))))
	{
		free_str_array(map);
		return (result_code);
	}
	params->map = map;
	params->rows_count = get_rows_count(map);
	params->columns_count = get_columns_count(map);
	if (!is_map_valid(params))
	{
		free_str_array(map);
		params->map = NULL;
		return (INVLD_MAP_ER);
	}
	substitute_chars(OUTER_SPACE, WALL, map);
	return (result_code);
}
