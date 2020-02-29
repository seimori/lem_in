/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 00:07:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define ARG_LEN_INIT_INT 1

t_specs		*remove_undefined_flags(t_specs *specs)
{
	if (specs->flags & ZERO && specs->flags & MINUS)
		specs->flags ^= ZERO;
	if ((!(specs->conversion == 'd') && !(specs->conversion == 'i'))
			&& specs->flags & PLUS)
		specs->flags ^= PLUS;
	if ((!(specs->conversion == 'd') && !(specs->conversion == 'i'))
			&& specs->flags & SPACE)
		specs->flags ^= SPACE;
	if ((specs->conversion == 'd' || specs->conversion == 'i')
			&& specs->lengthmodifier & BIG_L)
		specs->lengthmodifier ^= BIG_L;
	return (specs);
}

int			is_zero_exception(t_arg arg, t_specs *specs)
{
	if (arg.i == 0)
	{
		specs->is_zero = 1;
		if (specs->precision == 0
				&& (!(specs->flags & HASH && specs->conversion == 'o')))
		{
			specs->arg_len = 0;
			return (1);
		}
	}
	return (0);
}

int			print_int(t_arg arg, t_specs *specs)
{
	specs = remove_undefined_flags(specs);
	specs->arg_len = ARG_LEN_INIT_INT;
	if (is_zero_exception(arg, specs))
		return (print_options(specs));
	if (specs->conversion == 'd' || specs->conversion == 'i')
		specs->arg_len = print_signed_decimal(arg.lli, specs);
	else if (specs->conversion == 'u')
		specs->arg_len = print_unsigned_decimal(arg.llu, specs);
	else if (specs->conversion == 'o')
		specs->arg_len = print_octal(arg.llu, specs);
	else if (specs->conversion == 'x')
		specs->arg_len = print_hexadecimal(arg.llu, specs);
	else if (specs->conversion == 'X')
		specs->arg_len = print_hexadecimal_big(arg.llu, specs);
	return (specs->arg_len);
}
