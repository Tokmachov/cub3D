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

#include <stdlib.h>
#include "cub3d.h"

void	free_str_array(char **arr)
{
	char **tmp;

	if (arr == NULL)
		return ;
	tmp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

t_bool	is_error(int error_code)
{
	if (error_code != NO_ERROR)
		return (true);
	return (false);
}

int		count_words(char **str)
{
	int count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*skip_to_next_coma_separated_number_parameter(char *str)
{
	str = skip_digits(str);
	str = skip_spaces(str);
	if (*str != ',')
		return (NULL);
	str++;
	str = skip_spaces(str);
	return (str);
}

char	*skip_digits(char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}
