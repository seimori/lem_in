/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 18:46:51 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				manage_minus_flag(t_specs *specs, int count)
{
	if (specs->flags & MINUS && specs->conversion == 's')
		count = print_width_string(specs) + specs->arg_len;
	else if (specs->flags & MINUS)
	{
		specs->arg_len = print_precision(specs);
		count = print_width(specs) + specs->arg_len;
	}
	return (count);
}

int				print_arg(va_list args, t_specs *specs, t_fp_arg *print)
{
	t_arg		arg;
	int			count;

	if (specs->conversion == 'f')
		if (specs->lengthmodifier & BIG_L)
			arg = (t_arg)va_arg(args, long double);
		else
			arg = (t_arg)va_arg(args, double);
	else if (specs->conversion == 's')
		arg = (t_arg)va_arg(args, char*);
	else if (specs->conversion == '%')
		arg = (t_arg)'%';
	else if (specs->lengthmodifier & L || specs->conversion == 'p')
		arg = (t_arg)va_arg(args, long int);
	else if (specs->lengthmodifier & LL)
		arg = (t_arg)va_arg(args, long long int);
	else
		arg = (t_arg)va_arg(args, int);
	count = print[specs->typeindex](arg, specs);
	count = manage_minus_flag(specs, count);
	return (count);
}
