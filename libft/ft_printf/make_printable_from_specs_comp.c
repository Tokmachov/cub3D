/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_printable_from_specs_comp.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:18:03 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 13:42:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	free_specs(t_specifiers *specs)
{
	if (specs->arg_val_str)
		free(specs->arg_val_str);
	free(specs);
}

static	size_t	null_c_strlen(STRING str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	str++;
	len++;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

static	size_t	calc_printable_len(STRING str, t_specifiers specs)
{
	size_t	len;

	if (specs.arg_type == 'c' && *specs.arg_val_str == '\0')
		len = null_c_strlen(str);
	else
		len = ft_strlen(str);
	return (len);
}

t_printable_str	*make_printable_from_specs_comp(STRING comp, va_list args)
{
	t_specifiers	*specs;
	t_printable_str	*printable;
	size_t			strlen;
	STRING			str;

	specs = parse_specs(comp, args);
	if (!specs)
		return (NULL);
	str = convert_specs_to_str(*specs);
	if (!str)
	{
		free(specs);
		return (NULL);
	}
	strlen = calc_printable_len(str, *specs);
	printable = init_printable(str, strlen);
	free_specs(specs);
	return (printable);
}
