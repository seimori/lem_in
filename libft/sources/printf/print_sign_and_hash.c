/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_and_hash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:31:59 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 23:59:28 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				sign_offset(t_specs *specs)
{
	int			offset;

	offset = 0;
	if (specs->conversion == '%')
		return (0);
	if ((specs->is_negative == 1 || specs->flags & PLUS
				|| specs->flags & SPACE)
			&& !(is_hex_or_octal(specs)))
		offset += 1;
	return (offset);
}

int				hash_offset(t_specs *specs)
{
	int			offset;

	offset = 0;
	if (specs->conversion == '%')
		return (0);
	if (specs->flags & HASH && !(specs->is_zero))
	{
		if (specs->conversion == 'x' || specs->conversion == 'X'
				|| specs->conversion == 'p')
			offset += 2;
		else if (specs->conversion == 'o' && specs->precision < specs->arg_len
				&& !(specs->is_zero))
			offset += 1;
	}
	return (offset);
}

int				sign_and_hash_offset(t_specs *specs)
{
	int			offset;

	offset = 0;
	offset += sign_offset(specs);
	offset += hash_offset(specs);
	return (offset);
}

void			print_hash(t_specs *specs)
{
	if (specs->flags & HASH && !(specs->is_zero))
	{
		if (specs->conversion == 'x' || specs->conversion == 'p')
			ft_putstr("0x");
		else if (specs->conversion == 'X')
			ft_putstr("0X");
		else if (specs->conversion == 'o'
				&& specs->precision <= specs->arg_len
				&& !(specs->is_zero))
			ft_putstr("0");
	}
}

void			print_sign(t_specs *specs)
{
	if ((!(specs->flags & ZERO) || specs->precision > -1)
			&& !(specs->conversion == '%'))
	{
		if (specs->is_negative == 1)
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
		else if (specs->flags & SPACE)
			ft_putchar(' ');
	}
}
