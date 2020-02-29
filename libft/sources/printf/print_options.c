/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 17:57:51 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			print_flag_zero(t_specs *specs)
{
	char		width_char;

	width_char = ' ';
	if (specs->flags & ZERO && !(specs->flags & MINUS))
	{
		if (specs->precision <= -1)
		{
			width_char = '0';
			if (specs->is_negative)
				ft_putchar('-');
			else if (specs->flags & PLUS && is_signed(specs))
				ft_putchar('+');
			else if (specs->flags & SPACE && is_signed(specs))
				ft_putchar(' ');
		}
		if (specs->flags & HASH && (is_hex_or_octal(specs)))
			print_hash(specs);
	}
	return (width_char);
}

int				print_width(t_specs *specs)
{
	char		width_char;

	if (specs->conversion == 'f')
	{
		if (specs->special & INF || specs->special & NAN)
			specs->arg_len = 3;
		else if (specs->special & N_INF)
			specs->arg_len = 4;
	}
	width_char = print_flag_zero(specs);
	while (specs->spaces_len + specs->precision < specs->width
			&& specs->spaces_len + specs->arg_len < specs->width)
	{
		ft_putchar(width_char);
		specs->spaces_len++;
	}
	return (specs->spaces_len);
}

int				print_options(t_specs *specs)
{
	if (!(specs->flags & MINUS))
	{
		specs->spaces_len += sign_and_hash_offset(specs);
		specs->spaces_len = print_width(specs);
	}
	else
	{
		specs->spaces_len += sign_offset(specs);
		specs->arg_len += hash_offset(specs);
	}
	print_sign(specs);
	if (!(specs->flags & ZERO) || specs->flags & MINUS)
		print_hash(specs);
	specs->arg_len = print_precision(specs);
	if (!(specs->flags & MINUS))
		return (specs->spaces_len + specs->arg_len);
	else
		return (specs->arg_len);
}
