/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:35:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 14:32:07 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_width_string(t_specs *specs)
{
	char		width_char;

	width_char = ' ';
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		width_char = '0';
	while (specs->spaces_len + specs->arg_len < specs->width)
	{
		ft_putchar(width_char);
		specs->spaces_len++;
	}
	return (specs->spaces_len);
}
