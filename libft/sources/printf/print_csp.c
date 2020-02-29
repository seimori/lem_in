/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 00:24:19 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define ARG_LEN_INIT_INT 1

int				print_c(t_arg arg, t_specs *specs)
{
	specs->arg_len = 1;
	if (!(specs->flags & MINUS))
		specs->spaces_len = print_width_string(specs);
	ft_putchar(arg.c);
	return (specs->arg_len + specs->spaces_len);
}

int				print_s(t_arg arg, t_specs *specs)
{
	if (arg.s == NULL)
		return (print_null(specs));
	specs->arg_len = ft_strlen(arg.s);
	if (specs->arg_len > specs->precision && specs->precision > -1)
		specs->arg_len = specs->precision;
	if (!(specs->flags & MINUS))
		specs->spaces_len = print_width_string(specs);
	if (specs->precision <= -1 || specs->arg_len < specs->precision)
		ft_putstr(arg.s);
	else
		ft_putstrn(arg.s, specs->precision);
	return (specs->arg_len + specs->spaces_len);
}

int				print_p(t_arg arg, t_specs *specs)
{
	if (arg.p == 0 && specs->precision == 0)
	{
		specs->is_zero = 1;
		specs->arg_len += 2;
		ft_putstr("0x");
		return (print_width(specs) + specs->arg_len);
	}
	specs->arg_len = ARG_LEN_INIT_INT;
	specs->flags |= HASH;
	specs->arg_len = print_hexadecimal((unsigned long)arg.p, specs);
	return (specs->arg_len);
}
